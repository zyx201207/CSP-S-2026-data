#include<bits/stdc++.h>
//#define int long long
using namespace std;
const int N = 27;
const int inf = 0x3f3f3f3f;
int c,T;
int n,k;
vector<int>g[N];
int cnt(int x){
    int s=0;
    for(;x;x>>=1)
        s+=(x&1);
    return s;
}
bool in(int x,int p){
    return p&(1<<(x-1));
}
int dfs(int x,int p,int fa){
    if(in(x,p))
        return 0;
    int s=inf;
    for(int y:g[x]){
        if(y==fa)
            continue;
        s=min(s,dfs(y,p,x)+1);
    }
    return s;
}
void ini(){
    for(int i=1;i<N;i++){
        vector<int>l;
        g[i].swap(l);
    }
}
int f[N],sz[N];
void fini(){
    for(int i=1;i<=n;i++){
        f[i]=i;
        sz[i]=1;
    }
}
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
int uni(int x,int y){
    int fx=find(x),fy=find(y);
    if(fx==fy)
        return 0;
    if(sz[fx]>sz[fy])
        fx^=fy^=fx^=fy;
    sz[fy]+=sz[fx];
    f[fx]=fy;
    return 1;
}
signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>T;
    while(T--){
        cin>>n>>k;
        if(k==n){
            cout<<0<<endl;
            continue;
        }
        if(n>15){
            int m=(n-1)>>1;
            if(k>=m)
                cout<<1<<endl;
            else{
                // m+=2;
                double fm=m;
                int ans=ceil((fm-k)/4.0);
                cout<<ans+1<<endl;
            }
            continue;
        }
        ini();
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        int ans=inf;
        for(int p=1;p<(1<<n);p++){
            if(cnt(p)!=k)
                continue;
            fini();
            int cnt=0;
            for(int i=1;i<=n;i++)
                for(int j:g[i])
                    if(in(i,p)&&in(j,p))
                        cnt+=uni(i,j);
            if(cnt+2<k)
                continue;
            int dis=0;
            for(int i=1;i<=n;i++)
                if(!in(i,p))
                    dis=max(dis,dfs(i,p,0));
            ans=min(ans,dis);
        }
        cout<<ans<<endl;
    }
    return 0;
}
//wo yao da ming ri fang zhou
//wo yao wan arknights
//wo yao chou ka
//wo shi ren lei, wo yao shang mi huo xing wei da shang