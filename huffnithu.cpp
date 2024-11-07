#include<bits/stdc++.h>
using namespace std;
map<char,string> mp;
class huff{
public:
	char val='$';
	int freq=0;
	huff *left,*right;
	huff(char v,int f){
		val=v;
		freq=f;
		left=NULL;
		right=NULL;
	}
}; 
class compare{
public:
	bool operator()(huff* node1,huff* node2){
		return (node1->freq>node2->freq);
	}
};
    string ans=" ";
void printcode(huff* root , string s){

	if(root==NULL)return;
	if(root->val!='$'){
		mp[root->val]=s;
		cout<<root->val<<" "<<s<<endl;
       ans+=s; 

	}
    cout<<endl;
	printcode(root->left,s+'0');
	printcode(root->right,s+'1');
//  while(n--){
//     ans+=s;
//  }

  
}


int main(){
	int n;
	cin>>n;
    string en="";
	// cout<<1<<endl;
	priority_queue<huff* ,vector<huff*> ,compare> pq;
	for(int i=0;i<n;i++){
		int freq;
		char val;
		cin>>val>>freq;
		huff *node=new huff(val,freq);
		pq.push(node);
	}
	while(pq.size()!=1){
		huff *lleft =pq.top();
		pq.pop();
		huff *rright =pq.top();
		pq.pop();
		huff *root=new huff('$',(int)(lleft->freq+rright->freq));
		root->left=lleft;
		root->right=rright;

		pq.push(root);

	}
	string s="";
	huff * root=pq.top();
  

	printcode(root,s);
    cout<<ans;
    	cout<<"decode"<<endl;
	cin>>s;
      
	string code="";
	for(auto it:s){
		code+=mp[it];
	}
	cout<<code<<endl;



}