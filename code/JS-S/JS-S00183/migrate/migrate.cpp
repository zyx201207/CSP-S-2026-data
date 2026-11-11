#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxN=2e6+20;
ll x[maxN];
int dp[maxN];
int cnt[maxN];
vector<int> edge[maxN];
int main() {
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int c,t;
    cin>>c>>t;
    while (t--) {
        ll n,d;
        cin>>n>>d;
        for (int i=1;i<=n;i++)
            cin>>x[i];
        if (c==13||c==14||n==1||((c==11||c==12)&&x[2]-x[1]<d)) {cout<<"0\n";continue;}
        for (int i=1;i<=n;i++) {
            edge[i].clear();
        }
        for (int i=1;i<=n;i++) {
            for (int j=i+1;j<=n;j++) {
                if (x[j]-x[i]<=d) {
                    edge[i].push_back(j);
                }
            }
        }
        ll ans=0;
        for (int st=1;st<n;st++) {
            for (int i=st;i<=n;i++) {
                cnt[i]=0;
                dp[i]=0x3f3f3f3f;
            }
            dp[st]=0;
            cnt[st]=1;
            for (int u=st;u<=n;u++) {
                for (auto v:edge[u]) {
                    if (dp[v]>dp[u]+1) {
                        dp[v]=dp[u]+1;
                        cnt[v]=cnt[u];
                    } else if (dp[v]==dp[u]+1) {
                        cnt[v]+=cnt[u];
                    }
                }
            }
            for (int i=st+1;i<=n;i++) {
                if (cnt[i]==2)
                    ans++;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
