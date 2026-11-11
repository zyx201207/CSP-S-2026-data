#include <bits/stdc++.h>

#define int long long
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define rep_(i,l,r) for(int i=(l);i<(r);i++)
#define per(i,r,l) for(int i=(r);i>=(l);i--)
#define fi first
#define se second
#define mpr(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define endl "\n"
#define lowbit(x) (x&-x)
#define sz(s) ((int)s.size())
#define pii pair<int,int>
#define y0 y12345
#define y1 y54321

using  namespace std;

void inline solve(int C);

signed main(){
    srand(time(0));
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    int T=1,C=0;

    cin >> C;
    cin >> T;

    while(T--) solve(C);

    return 0;
}

const int N=2e6+10;

int n,d,x[N],nxt[N],ans;

map<int,int> dp[3];

int dfs(int _i,int i,int j,int k){
    if(!i) return 0;
    int res=0;
    if(j) res=j-max(_i,k);
    if(i==n || nxt[i]==i) return res;
    int mask=i*(n+1)*(n+1)+j*(n+1)+k;
    int x=min(2ll,i-_i);
    if(dp[x].find(mask)!=dp[x].end()) return dp[x][mask];
    int i_=nxt[i];
    int j_=nxt[j];
    int k_=nxt[k];
    if(_i<=i-1 && nxt[i-1]>=j_) k_=j_,j_=nxt[i-1];
    else if(_i<=i+1) k_=max(k_,nxt[i-1]);
    if(_i<=i-2) k_=max(k_,nxt[i-2]);
    return dp[x][mask]=res+dfs(i,i_,j_,k_); 
}

void inline solve(int C){
    cin >> n >> d;
    rep(i,1,n) cin >> x[i];
    for(int i=n,j=n;i>=1;i--){
        while(x[j]-x[i]>d) j--;
        nxt[i]=j;
    }
    ans=0;
    rep(i,0,2) dp[i].clear();
    rep(i,1,n) ans+=dfs(i,i,0,0);
    cout << ans << endl;
}