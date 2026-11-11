#include<bits/stdc++.h>
using namespace std;
int td1,td2;
int c,n,m,d,qq,len,s,t,h[500006],tt[506][500006];
long long ans,di[506];
vector<int> a[500006];
vector<pair<int,long long> > g[506];
priority_queue<pair<long long,int>,vector<pair<long long,int> >,greater<pair<long long,int> > > q;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>qq;
    for(int i=1;i<=m;i++) cin>>h[i];
    for(int i=1;i<=n;i++){
        cin>>len;
        for(int j=1;j<=len;j++){
            cin>>td1>>td2;
            if(a[td1].size()){
                for(auto u:a[td1]){
                    g[i].push_back({u,td2+tt[u][td1]});
                    g[u].push_back({i,td2+tt[u][td1]});
                }
            }
            a[td1].push_back(i);
            tt[i][td1]=td2;
        }
    }
    while(qq--){
        ans=4e18;
        int ps1=0,ps2=0;
        cin>>s>>t;
        for(auto j:a[s]){
            for(int i=1;i<=n;i++) di[i]=1e18;
            di[j]=0;
            q.push({0,j});
            while(!q.empty()){
                auto pi=q.top();q.pop();
                int dis=pi.first;
                int u=pi.second;
                if(dis>di[u]) continue;
                for(auto vv:g[u]){
                    int v=vv.first;
                    int w=vv.second;
                    if(di[v]>di[u]+w){
                        di[v]=di[u]+w;
                        q.push({di[v],v});
                    }
                }
            }
            for(auto k:a[t]){
                if(ans>di[k]){
                    ans=di[k];
                    ps1=j;
                    ps2=k;
                }
            }
        }
        ans=ans+h[s]+tt[ps1][s]+h[t]+tt[ps2][t];
        cout<<ans<<'\n';
    }
    return 0; 
}