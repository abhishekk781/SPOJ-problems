#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define MOD 1000000007

vector < pair<int,int> > G[10005];
lli dis[10005];
//int cnt=0;
void dikstra(int x){
    std::priority_queue<int, std::vector<int>, std::greater<int> > q;
    q.push(x);
    dis[x]=0;
    while(!q.empty()){
        int u=q.top();
        q.pop();
        for(int i=0;i<G[u].size();i++){
            int v=G[u][i].first;
            int cost=G[u][i].second;
            if(dis[v]>dis[u]+cost){
                dis[v]=dis[u]+cost;
                q.push(v);
            }
        }
    }
}
int main()
{
    //std::ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    int t;
    scanf("%d",&t);
    while(t--){
        map <string,int> mp;
        int n;
        scanf("%d",&n);
        for(int i=0;i<=n;i++){ G[i].clear(); }
        int no=1;
        for(int i=0;i<n;i++){
            string s;
            cin>>s;
            mp.insert(make_pair(s,no));
            int p;
            scanf("%d",&p);
            for(int j=0;j<p;j++){
                int x,cost;
                scanf("%d%d",&x,&cost);
                G[no].push_back(make_pair(x,cost));
            }
            no++;
        }
        int q;
        scanf("%d",&q);
        while(q--){
            for(int i=0;i<=n;i++){ dis[i]=100000000000; }
            string s1,s2;
            cin>>s1>>s2;
            int index1,index2;
            map <string,int> ::iterator it;
            it=mp.find(s1);
            index1=it->second;
            it=mp.find(s2);
            index2=it->second;
            dikstra(index1);
            //cout<<dis[index2]<<endl;
            printf("%lli\n",dis[index2]);
        }
    }
    return 0;
}
