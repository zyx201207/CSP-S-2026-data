#include<bits/stdc++.h>
using namespace std;
int h[2000010];
int n,k,id[2000010],eu[2000010],ev[2000010];
int Max[2000010],cMax[2000010],f[2000010];
vector<pair<int,int> >e[2000010];
void dfs1(int now,int fa){
    for(auto [to,id]:e[now])
        if(to!=fa){
            dfs1(to,now);
            if(Max[to]+1>Max[now])
                cMax[now]=Max[now],
                Max[now]=Max[to]+1;
            else if(Max[to]+1>cMax[now])
                cMax[now]=Max[to]+1;
        }
}
void dfs2(int now,int fa,int d){
    if(d>Max[now])f[Max[now]]++;
    else if(d>cMax[now])f[d]++;
    else f[cMax[now]]++;
    for(auto [to,id]:e[now])
        if(to!=fa)
            dfs2(to,now,max(d+1,((Max[to]+1==Max[now])?cMax[now]:Max[now])));
}
void solve(){
    cin>>n>>k;
    for(int i=1;i<=n;i++)e[i].clear();
    for(int i=1,u,v;i<n;i++){
        cin>>u>>v;
        eu[i]=u,ev[i]=v;
        id[i]=i;
        e[u].push_back({v,i});
        e[v].push_back({u,i});
    }
    if(k==n){
        cout<<0<<'\n';
        return;
    }
    random_shuffle(id+1,id+n);
    int qwq=min(n-1,(2000000)/n);
    int res=n;
    for(int i=1;i<qwq;i++){
        for(int i=0;i<=n;i++)Max[i]=cMax[i]=0,f[i]=0;
        dfs1(eu[id[i]],ev[id[i]]);
        dfs1(ev[id[i]],eu[id[i]]);
        dfs2(eu[id[i]],ev[id[i]],0);
        dfs2(ev[id[i]],eu[id[i]],0);
        int sum=0;
        for(int j=n;j>=0;j--){
            sum+=f[j];
            if(sum>k){
                res=min(res,j+1);
                //if(j+1==188)cerr<<i<<'\n';
                //for(int k=1;k<n;k++)
                //    if()
                break;
            }
        }
    }
    cout<<res<<'\n';
    return;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int c,t;cin>>c>>t;
    while(t--)solve();
    return 0;
}