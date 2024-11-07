#include<bits/stdc++.h>
using namespace std;

//quicksort

int partition(vector<int> &arr,int low,int high){
    // int randomIndex=low+rand()%(high-low+1);
    // swap(arr[low],arr[randomIndex]);
    int pivot=arr[low];
    int i=low,j=high;

    while(i<j){
        while(arr[i]<=pivot && i<high){
            i++;
        }
        while(arr[j]>pivot && j>low){
            j--;
        }
        if(i<j)swap(arr[i],arr[j]);
        
    }
    swap(arr[low],arr[j]);
    return j;
}

void quickSort(vector<int> &arr,int low,int high){
    if(low<high){
        int pIndex=partition(arr,low,high);
        quickSort(arr,low,pIndex-1);
        quickSort(arr,pIndex+1,high);
    }
}

void quickSortCode(){
    int n;
    cout<<"enter number of elements\n";
    cin>>n;
    vector<int> arr(n);
    cout<<"enter the elements\n";
    for(auto &it:arr)cin>>it;
    quickSort(arr,0,n-1);
    for(auto &it:arr)cout<<it<<" ";
    cout<<endl;
}
//quicksort ------------------------------

//nqueens 

bool isSafe(vector<vector<char>>&board,int row,int col){
    for(int i=0;i<row;i++){
        if(board[i][col]=='Q')return 0;
    }
    
    for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--){
        if(board[i][j]=='Q')return 0;
    }

    for(int i=row-1,j=col+1;i>=0 && j<board.size();i--,j++){
        if(board[i][j]=='Q')return 0;
    }

    return 1;
}

void nqueens(vector<vector<char>>&board,int row){
    if(row==board.size()){
        for(auto it:board){
            for(auto t:it){
                cout<<t<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        return;
    }

    for(int col=0;col<board.size();col++){
        if(isSafe(board,row,col)){
            board[row][col]='Q';
            nqueens(board,row+1);
            board[row][col]='.';

        }
    }

}

void nqueensCode(){
    cout<<"enter box length\n";
    int n;
    cin>>n;
    vector<vector<char>>board(n,vector<char>(n,'.'));
    int row=0;
    nqueens(board,0);

    // for(auto it:board){
    //     for(auto t:it){
    //         cout<<t<<" ";
    //     }
    //     cout<<endl;
    // }
}

//nqueens ---------------------------------

//huffmanCoding

class node{
  public:  
    char character;
    int freq;
    node* left;
    node* right;
    node(char c,int freq){
        this->character=c;
        this->freq=freq;
        left=right=NULL;
    }
};
struct comparator{
    bool operator()(node* a,node* b){
        return a->freq>b->freq;
    }
};

void printCode(node* cur,string s){
    if(!cur)return;
    if(cur->character!='$'){
        cout<<cur->character<<" "<<s<<endl;
    }
    printCode(cur->left,s+"0");
    printCode(cur->right,s+"1");
}

void huffmanCoding(){
    int n;
    cout<<"enter num of characters\n";
    cin>>n;
    vector<pair<char,int>>CharFreq(n);
    
    cout<<"now eneter charater and their frequency\n";
    for(auto &it:CharFreq){
        char c;
        int freq;
        cin>>c>>freq;
        it={c,freq};
    }
    cout<<endl;

    priority_queue<node*,vector<node*>,comparator> minHeap;


    for(auto it:CharFreq){
        minHeap.push(new node(it.first,it.second));
    }

    while(minHeap.size()!=1){

        node* left=minHeap.top();
        minHeap.pop();

        node* right=minHeap.top();
        minHeap.pop();

        node* top=new node('$',left->freq+right->freq);
        top->left=left;
        top->right=right;

        minHeap.push(top);

    }
    cout<<"huffman coding of characters are \n";
    printCode(minHeap.top(),"");
}
// char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' }; 
//     int freq[] = { 5, 9, 12, 13, 16, 45 }; 
// f 0
// c 100
// d 101
// a 1100
// b 1101
// e 111


//huffmanCoding----------------------------





int main(){
    srand(time(0));// random generator seed

    int option;
    cout<<"enter the 1 for quickSort \nenter the 2 for nQueens with backtracking \nenter 3 for huffmanCoding \n";
    cin>>option;
    switch (option)
    {
    case 1:
        quickSortCode();
        break;
    case 2:
        nqueensCode();
        break;

    case 3:
        huffmanCoding();
        break;
    default:
        cout<<"sorry no such options available\n";
        break;
    }


}