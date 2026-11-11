#include<bits/stdc++.h>
#define forr(i,a,b) for(int i=a;i<=b;i++)
#define ll long long
#define PII pair<int,int>
using namespace std;
const int N=5e5+10;
int w[N],k[N];
int c,n,m,d,q;
int x,y;
struct Node{
    int v,w;
};
priority_queue<PII,vector<PII>,greater<PII> >pq;
int dis[550];
vector<Node>g[550];
void di(){
    pq.push({0,x});
    dis[x]=0;
    while(pq.size()){
        auto x=pq.top();
        pq.pop();
        int v=x.first,w=x.second;
        for(auto xx:g[v]){
            int ww=xx.w;
            int vv=xx.v;
            if(dis[v]<dis[vv]+ww)continue;

        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    forr(i,1,m)cin>>w[i];
    int maxk=-1;
    forr(i,1,n){
        cin>>k[i];
        forr(j,1,k[i]){
            int aa,tt;
            cin>>aa>>tt;
            g[i].push_back({aa,tt});
        }
        maxk=max(maxk,k[i]);
    }
    // forr(i,1,n){
    //     auto d=g[i];
    //     printf("%d:(%d)\n",i,d.size());
    //     for(auto f:g[i]){
    //         printf("%d->%d:%d\n",i,f.v,f.w);
    //     }
    // }
    forr(i,1,q){
        cin>>x>>y;
        cout<<w[x]+w[y]<<endl;
    }
    return 0;
}