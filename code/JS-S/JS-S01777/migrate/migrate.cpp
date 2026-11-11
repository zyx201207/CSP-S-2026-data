#include<bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll N=5005;
constexpr ll inf = (1ll<<60);
ll dis[N][N], cnt[N][N], a[N];
ll c, T, n, d, ans;
ll dfs(ll s, ll t) {
    if(dis[s][t]!=-1) return dis[s][t];
    ll mn = inf;
    for(int i=s+1; i<t; i++) mn = min(mn, dfs(s,i)+dfs(i,t));
    if(a[t]-a[s] <= d) mn=1;
    return dis[s][t]=mn;
}
ll check(ll s, ll t, ll w) {
    //cout << s << ' '<< t << ' '<< w <<'\n';
    if(w==0&&s<t) return 0;
    if(s==t) return 1;
    ll cnt=0;
    for(int i=s+1; i<=t; i++) {
        if(a[i]-a[s]>d) break;
        cnt+=check(i,t,w-1);
    }
    return cnt;
}
int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out","w",stdout);
    cin.tie(0),cout.tie(0)->sync_with_stdio(0);
    cin >> c >> T;
    while(T--) {
        cin >> n >> d;
        for(int i=1; i<=n; i++) cin >> a[i];
        //for(int i=1; i<=n; i++) cout << a[i] << '\n';
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                dis[i][j]=-1;
                cnt[i][j]=0;
            }
            dis[i][i]=0;
        }
        for(int i=1; i<n; i++) {
            if(a[i+1]-a[i]<=d) dis[i][i+1]=1,cnt[i][i+1]=1;
            else dis[i][i+1]=inf,cnt[i][i+1]=0;
        }
        for(int i=1; i<=n; i++) {
            for(int j=i; j<=n; j++) {
                dfs(i,j);
                //dis[i][j]=-1;
                //cnt[i][j]=0;
            }
        }
        //cout << check(1,4,10000) << '\n';
        ll ans=0;
        for(int i=1; i<=n; i++) {
            for(int j=i; j<=n; j++) {
                //cout << check(i,j,dis[i][j]) << ' ';
                if(check(i,j,dis[i][j])==2) ans++;
            }//cout << '\n';
        }
        cout << ans << '\n';
    }
    return 0;
}
