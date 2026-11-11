#include <bits/stdc++.h>
#define int long long
#define MP make_pair
#define st first
#define nd second
#define rep(i,a,b) for(int i=a;i<b;i++)
#define REP(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
const int N=5005,INF=1e18+76;
int n,d,l[N],r[N],x[N],fa[N],lst[N];
int find(int u){
    return fa[u]==u?u:fa[u]=find(fa[u]);
}
int calc(int s){
    queue<int> w;
    vector<int> d(n+1,0),x(n+1,0);
    rep(i,0,n+1)d[i]=INF,fa[i]=i,lst[i]=n;
    w.push(s);
    x[s]=1;
    while(w.size()){
        int u=w.front();
        w.pop();
        //u+1,r[i]
        for(int v=find(u+1);v<=r[u];v=find(v+1)){
            if(d[v]==INF)d[v]=d[u]+1,x[v]=x[u],w.push(v);
            else if(d[u]+1==d[v])(x[v]+=x[u])%=INF;
            lst[v]--;
            if(lst[v]==0)fa[v]=v+1;
        }
    }
    int res=0;
    rep(i,s+1,n)if(x[i]==2)res++;
    return res;
}//O(n)
void solve(){
    cin>>n>>d;
    rep(i,0,n)cin>>x[i];
    rep(i,0,n)r[i]=upper_bound(x,x+n,x[i]+d)-x-1;
    int ans=0;
    rep(i,0,n)ans+=calc(i);
    cout<<ans<<endl;
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,T;
    cin>>c>>T;
    while(T--)solve();
    return 0;
}
