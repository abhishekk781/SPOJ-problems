#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define MOD 1000000007
bool ans=true;
struct node{
    int flag;
    node *dig[10];
    node(){
        flag=0;
        for(int i=0;i<10;i++){
            dig[i]=NULL;
        }
    }
};
void insert(node *root,string val){
    int i=0,fg=0;
    while(i<val.size()){
        int a=val[i]-'0';
        //cout<<a<<" ";
        if(root->dig[a]==NULL){ root->dig[a]=new node; fg=1; }
        root=root->dig[a];
        if(root->flag==1){ ans=false; }
        i++;
    }
    if(fg==0){ ans=false; }
    root->flag=1;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        node *trie=new node;
        ans=true;
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            string x;
            cin>>x;
            insert(trie,x);
        }
        if(ans==false){ cout<<"NO"<<endl; }
        else{ cout<<"YES"<<endl;  }
    }
    return 0;
}
