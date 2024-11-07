#include<bits/stdc++.h>
using namespace std;
map<char,string>mp;
struct node{
    char data='$';
    int fre=0;
    node* left;
    node* right;
    node(char data,int fre){
       this-> data=data;
      this-> fre=fre;
        left=NULL;
        right=NULL;

    }
};

struct cmp{
    bool operator()(node* left,node*right){
        return (left->fre >right->fre);
    }
};
string ans;
void prnt(node* root, string s) {
    if (root == NULL) {
        return;
    }
    if (root->data != '$') {
        mp[root->data] = s;
        cout << root->data << "  " << s << endl;
        ans += s;
    }
    prnt(root->left, s + '0');
    prnt(root->right, s + '1');
}



int main(){

int n;
cout<<"no of characters u want to enter"<<endl;
cin>>n;
priority_queue<node* ,vector<node*>,cmp>pq;
for(int i=0;i<n;i++){
    int fre;
    char data;
    cin>>data>>fre;
    node *newnode=new node(data,fre);
    pq.push(newnode);
}
while(pq.size()!=1){
node * lleft=pq.top();
pq.pop();
node * rright=pq.top();
pq.pop();
int sum=lleft->fre+rright->fre;
node* root=new node('$',sum);
root->left=lleft;
root->right=rright;
pq.push(root);


}
string s="";
node* root=pq.top();
prnt(root,s);
cin>>s;
cout<<ans;
cout<<"decode"<<endl;

string code="";
for(auto it:s){
code+=mp[it];
}
cout<<code;









    
}
