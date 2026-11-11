#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2000010;
int c,T,n,K;
int h[N],e[N],ne[N],idx;
vector<int> vec[N];
void add(int a,int b){
    e[++idx]=b,ne[idx]=h[a],h[a]=idx;
    e[++idx]=a,ne[idx]=h[b],h[b]=idx;
    vec[a].push_back(b),vec[b].push_back(a);
}
namespace Sub1{
    int rt=0,star;
    int v[N],fa[N],ans;
    bool check(){
        return n<=100;
    }
    void dfs(int u,int f,int val){
        if(u==star) val=0;
        v[u]=val;fa[u]=f;
        for(int i=h[u];i;i=ne[i]){
            int j=e[i];
            if(j==f) continue;
            dfs(j,u,val+1);
        }
    }
    void dfss(int u,int f,int val){
        if(u==rt) val=0;
        v[u]=min(v[u],val);
        for(int i=h[u];i;i=ne[i]){
            int j=e[i];
            if(j==f) continue;
            dfss(j,u,val+1);
        }
    }
    bool vis[N];
    bool CHECK(int l){
        for(int i=1;i<=n;i++) vis[i]=0;
        vis[star]=vis[rt]=1;
        for(int i=1;i<=n;i++){
            if(v[i]>l){
                int tmp=0,nod=i;
                while(tmp!=l) nod=fa[nod],tmp++;
                while(nod!=star&&nod!=rt) vis[nod]=1,nod=fa[nod];
            }
        }
        int calc=0;
        for(int i=1;i<=n;i++) if(vis[i]) calc++;
        if(calc>K) return 0;
        return 1;
    }
    void solve(){
        ans=1e18;
        for(rt=1;rt<=1;rt++){
            for(star=rt+1;star<=n;star++){
                dfs(rt,0,0);
                dfss(star,0,0);
                int l=0,r=n;
                while(l<r){
                    int mid=l+r>>1;
                    if(CHECK(mid)) r=mid;
                    else l=mid+1;
                }
                ans=min(ans,l);
            }
        }
        cout<<ans<<"\n";
    }
}
namespace Sub2{
    bool check(){
        return c==13||c==14;
    }
    int m;
    bool Check(int len){
        /*int nw=0,calc=0;
        while(nw<m) calc++,nw+=(2*len-1);
        if(calc>K) return 0;
        return 1;*/
        int ini=2*(2*len-1);
        ini=ini+(K-2);
        if(ini<m) return 0;
        return 1;
    }
    void solve(){
        m=n/2;
        if(K==n){
            cout<<"0\n";
            return;
        }
        if(K>=m){
            cout<<"1\n";
            return;
        }
        int l=1,r=n;
        while(l<r){
            int mid=l+r>>1;
            if(Check(mid)) r=mid;
            else l=mid+1;
        }
        cout<<l<<"\n";
    }
}
#define pii pair<int,int>
vector<pii> edg;
namespace Sub3{
    bool check(){
        return n<=1000&&K==2;
    }
    bool ban[1010][1010],vis[1010];
    int mx[1010],tmplen=0;
    void dfs(int u,int f){
        mx[u]=0;
        for(int i=h[u];i;i=ne[i]){
            int j=e[i];
            if(j==f||ban[u][j]) continue;
            dfs(j,u);
            tmplen=max(tmplen,mx[u]+mx[j]+1);
            mx[u]=max(mx[u],mx[j]+1);
        }
    }
    void solve(){
        int ans=1e18;
        for(auto ed:edg){
            ban[ed.first][ed.second]=ban[ed.second][ed.first]=1;
            tmplen=0;
            dfs(ed.first,0);
            int res=0;
            res=max(res,(tmplen+1)/2);
            dfs(ed.second,0);
            res=max(res,(tmplen+1)/2);
            ans=min(ans,res);
            ban[ed.first][ed.second]=ban[ed.second][ed.first]=0;
        }
        cout<<ans<<"\n";
    }
}
void Solve(){
    cin>>n>>K;int a,b;
    for(int i=1;i<=n;i++) h[i]=0,vec[i].clear();idx=0;
    edg.clear();
    for(int i=1;i<n;i++) cin>>a>>b,add(a,b),edg.push_back({a,b});
    if(Sub1::check()) return Sub1::solve();
    if(Sub2::check()) return Sub2::solve();
    if(Sub3::check()) return Sub3::solve();
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin.tie(0),cout.tie(0);ios::sync_with_stdio(false);
    cin>>c>>T;while(T--) Solve();
    return 0;
}