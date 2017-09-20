#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define ulli unsigned long long int
#define MOD 1000000007
#define p_b push_back
#define m_p make_pair

int n;
struct query{
    int l;
    int r;
    int index;
};
bool comp(query a,query b){
    int x=sqrt(n);
    if( (a.l)/x == (b.l)/x){ return a.r<b.r; }
    return (a.l)/x<(b.l)/x;
}
int main()
{
    scanf("%d",&n);
    vector <int> ar;
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        ar.p_b(x);
    }
    int q;
    cin>>q;
    vector <query> qr(q);
    for(int i=0;i<q;i++){
        int l,r;
        scanf("%d%d",&l,&r);
        l--; r--;
        qr[i].l=l;
        qr[i].r=r;
        qr[i].index=i;
    }
    sort(qr.begin(),qr.end(),comp);
    int count_ans=0;
    int hash1[1000001]={0};
    int ans[2000003]={0};
    int start=0,end=0;
    hash1[ar[0]]++; count_ans++;
    for(int i=0;i<q;i++){
        int l=qr[i].l,r=qr[i].r;
        //cout<<l<<" "<<" "<<r<<" "<<qr[i].index<<" "<<qr[i].s1<<endl;
        while(l<start){
            start--;
            if(hash1[ar[start]]==0){ count_ans++; }
            hash1[ar[start]]++;
        }
        while(l>start){
            if(hash1[ar[start]]==1){ count_ans--; }
            hash1[ar[start]]--;
            start++;
        }
        while(r<end){
            if(hash1[ar[end]]==1){ count_ans--; }
            hash1[ar[end]]--;
            end--;
        }
        while(r>end){
            end++;
            if(hash1[ar[end]]==0){ count_ans++; }
            hash1[ar[end]]++;
        }
        ans[qr[i].index]=count_ans;
    }
    for(int i=0;i<q;i++){
        cout<<ans[i]<<endl; 
    }
    return 0;
}
