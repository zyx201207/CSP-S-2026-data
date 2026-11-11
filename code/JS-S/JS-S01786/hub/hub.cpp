#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
vector<int>e[N];
int c,T,n,k,x,y;
int fst[N],scd[N],fstson[N],uplen[N],minlen,id;
int father[N],len[N],cnt;
void dfs3(int u,int fa,int d){
    int maxlen=0;
    len[u]=1;
    for(int i=0;i<e[u].size();++i){
        int v=e[u][i];
        if(v==fa) continue;
        dfs3(v,u,d);
        maxlen=max(maxlen,len[v]);
    }
    if(maxlen==d){
        cnt++;
        len[u]=-1;
    }else len[u]=maxlen+1;
}
bool check(int d){
    cnt=0;
    dfs3(id,0,d);
    return cnt<=k;
}
void dfs1(int u,int fa){
    fst[u]=scd[u]=fstson[u]=0;
    for(int i=0;i<e[u].size();++i){
        int v=e[u][i];
        if(v==fa) continue;
        dfs1(v,u);
        father[v]=u;
        if(fst[v]>fst[u]){
            scd[u]=fst[u];
            fst[u]=fst[v];
            fstson[u]=v;
        }else if(fst[v]>scd[u]) scd[u]=fst[v];
    }
    fst[u]++;
    scd[u]++;
}
void dfs2(int u,int fa){
    if(u!=1){
        if(max(uplen[u],fst[u])<minlen){
            minlen=max(uplen[u],fst[u]);
            id=u;
        }
    }
    for(int i=0;i<e[u].size();++i){
        int v=e[u][i];
        if(v==fa) continue;
        if(v==fstson[u]) uplen[v]=max(scd[u],uplen[u])+1;
        else uplen[v]=max(fst[u],uplen[u])+1;
        dfs2(v,u);
    }
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>T;
    while(T--){
        cin>>n>>k;
        for(int i=1;i<=n;++i) e[i].clear();
        for(int i=1;i<n;++i){
            cin>>x>>y;
            e[x].push_back(y);
            e[y].push_back(x);
        }
        if(n==k){
            cout<<0<<'\n';
            continue;
        }
        father[1]=e[1][0];
        dfs1(1,0);
        minlen=fst[1];
        id=1;
        uplen[1]=1;
        dfs2(1,0);
        dfs1(id,0);
        int l=1,r=n-2,ans;
        while(l<=r){
            int mid=l+r>>1;
            if(check(mid)){
                ans=mid;
                r=mid-1;
            }else l=mid+1;
        }
        cout<<ans<<'\n';
    }
    return 0;
}
