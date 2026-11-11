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

    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    int T=1,C=0;

    //cin >> C;
    //cin >> T;

    while(T--) solve(C);

    return 0;
}

const int N=5e5+10;

int n,m,a[N],s[N],ans;

void inline solve(int C){
    cin >> n >> m;
    rep(i,1,n) cin >> a[i];
    sort(a+1,a+1+n);
    rep(i,1,n) s[i]=s[i-1]+a[i];
    for(int i=1,j=1;i<=n;i++){
        while(a[i]*(i-j+1)-(s[i]-s[j-1])>m) j++;
        ans=max(ans,i-j+1);
    }
    cout << ans << endl;
}
