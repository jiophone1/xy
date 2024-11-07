#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

// Huffman Tree node
struct Node {
    char ch;
    int freq;
    Node* left;
    Node* right;

    Node(char ch, int freq) : ch(ch), freq(freq), left(nullptr), right(nullptr) {}
};

// Custom comparator for priority queue (min-heap)
struct Compare {
    bool operator()(Node* l, Node* r) {
        return l->freq > r->freq;
    }
};

// Function to generate Huffman Codes
void generateCodes(Node* root, const string& code, unordered_map<char, string>& huffmanCode) {
    if (!root)
        return;

    // If this node is a leaf node (it has a character)
    if (!root->left && !root->right)
        huffmanCode[root->ch] = code;

    generateCodes(root->left, code + "0", huffmanCode);
    generateCodes(root->right, code + "1", huffmanCode);
}

// Main function to build the Huffman Tree and get the codes
unordered_map<char, string> huffmanEncoding(char arr[], int freq[], int n) {
    // Create a priority queue to store live nodes of the Huffman Tree
    priority_queue<Node*, vector<Node*>, Compare> pq;

    // Create a leaf node for each character and add it to the priority queue
    for (int i = 0; i < n; i++) {
        pq.push(new Node(arr[i], freq[i]));
    }

    // Iterate until we have only one node left in the priority queue
    while (pq.size() > 1) {
        // Remove the two nodes of lowest frequency
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();

        // Create a new internal node with these two nodes as children
        int sum = left->freq + right->freq;
        Node* newNode = new Node('\0', sum);
        newNode->left = left;
        newNode->right = right;

        // Add the new node to the priority queue
        pq.push(newNode);
    }

    // The root of the Huffman Tree
    Node* root = pq.top();

    // Generate Huffman Codes by traversing the tree
    unordered_map<char, string> huffmanCode;
    generateCodes(root, "", huffmanCode);

    return huffmanCode;
}

int main() {
    char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    int freq[] = { 5, 9, 12, 13, 16, 45 };
    int n = sizeof(arr) / sizeof(arr[0]);

    // Perform Huffman Encoding
    unordered_map<char, string> huffmanCode = huffmanEncoding(arr, freq, n);

    cout << "Huffman Codes:\n";
    for (auto pair : huffmanCode) {
        cout << pair.first << " : " << pair.second << endl;
    }

    return 0;
}
