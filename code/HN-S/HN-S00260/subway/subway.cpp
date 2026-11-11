#include<bits/stdc++.h>
#define ll long long
#define f(i,a,n) for(int i=a;i<=n;i++)
using namespace std;
const int N=500005;
int c,n,m,T,y;
vector<pair<int,ll>>a[N<<1];
ll d[N<<1];
#define pii pair<int,int>
priority_queue<pii,vector<pii>,greater<pii>>q,emp;
void dij(int &rt){
    q=emp;
    q.push({0,rt});
    f(i,1,m)d[i]=0x3f3f3f3f3f3f;
    f(i,1,n)d[i+N]=0x3f3f3f3f3f3f;
    d[rt]=0;
    while(!q.empty()){
        ll x=q.top().first;
        int u=q.top().second;
        q.pop();
        if(x>d[u])continue;
        for(auto &i:a[u]){
            int &v=i.first;
            ll &w=i.second;
            if(x+w<d[v]){
                d[v]=x+w;
                if(v==y)return;
                q.push({d[v],v});
            }
        }
    }
}
int w[N];
int main(){ // O(q*k log k)
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>c>>n>>m>>T>>T;
    f(i,1,m)cin>>w[i];
    f(i,1,n){
        int k,l;
        cin>>k;
        f(j,1,k){
            int x,t;
            cin>>x>>t;
            a[x].push_back({i+N,t}); // 站厅到站台 
            a[i+N].push_back({x,t}); // 站台到站厅 
        }
    }
    while(T--){
        int x;
        cin>>x>>y;
        dij(x);
        cout<<w[x]+w[y]+d[y]<<'\n';
    }
    return 0;
}
