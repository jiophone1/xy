#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;

// Node structure for the Huffman tree
struct Node {
    char data;          // Character stored in the node
    int frequency;      // Frequency of the character
    Node* left;         // Pointer to the left child node
    Node* right;        // Pointer to the right child node

   Node(char data, int frequency) {
    this->data = data;
    this->frequency = frequency;
    left = nullptr;
    right = nullptr;
}

};

// Function to create a new node
Node* createNode(char data, int frequency) {
    Node* newNode = new Node(data, frequency);
    return newNode;
}

// Custom comparator for priority queue
struct Compare {
    bool operator()(Node* left, Node* right) {
        return left->frequency > right->frequency;
    }
};

// Function to check if a node is a leaf node
bool isLeaf(Node* node) {
    return node->left == nullptr && node->right == nullptr;
}

// Function to encode the characters using Huffman codes
void encodeCharacters(Node* root, string code, unordered_map<char, string>& huffmanCodes) {
    if (root == nullptr) {
        return;
    }

    if (isLeaf(root)) {
        huffmanCodes[root->data] = code;
        return;
    }

    encodeCharacters(root->left, code + "0", huffmanCodes);
    encodeCharacters(root->right, code + "1", huffmanCodes);
}

// Function to decode the encoded string using the Huffman tree
string decodeString(Node* root, string encodedString) {
    string decodedString = "";
    Node* current = root;

    for (char bit : encodedString) {
        if (bit == '0') {
            current = current->left;
        } else {
            current = current->right;
        }

        if (isLeaf(current)) {
            decodedString += current->data;
            current = root;
        }
    }

    return decodedString;
}

// Function to build the Huffman tree
Node* buildHuffmanTree(const unordered_map<char, int>& frequencies) {
    priority_queue<Node*, vector<Node*>, Compare> pq;

    // Create a leaf node for each character and add it to the priority queue
    for (const auto& pair : frequencies) {
        char data = pair.first;
        int frequency = pair.second;
        pq.push(createNode(data, frequency));
    }

    // Build the Huffman tree
    while (pq.size() > 1) {
        Node* left = pq.top();
        pq.pop();
        Node* right = pq.top();
        pq.pop();

        int sumFrequency = left->frequency + right->frequency;
        Node* newNode = createNode('\0', sumFrequency);
        newNode->left = left;
        newNode->right = right;

        pq.push(newNode);
    }

    // Return the root of the Huffman tree
    return pq.top();
}

int main() {
    string inputString;
    cout << "Enter the string to encode: ";
    getline(cin, inputString);

    unordered_map<char, int> frequencies;
    for (char ch : inputString) {
        frequencies[ch]++;
    }

    Node* root = buildHuffmanTree(frequencies);

    unordered_map<char, string> huffmanCodes;
    encodeCharacters(root, "", huffmanCodes);

    cout << "\nHuffman Codes:" << endl;
    for (const auto& pair : huffmanCodes) {
        cout << pair.first << " : " << pair.second << endl;
    }

    string encodedString = "";
    for (char ch : inputString) {
        encodedString += huffmanCodes[ch];
    }

    cout << "\nEncoded String: " << encodedString << endl;

    string decodedString = decodeString(root, encodedString);

    cout << "\nDecoded String: " << decodedString << endl;

    return 0;
}
