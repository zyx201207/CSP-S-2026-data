#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F(i, a, b) for (int i = (a); i <= (b); i ++ )
#define DF(i, a, b) for (int i = (a); i >= (b); i -- )
inline void chkmin(int& a, int b) { if (a > b) a = b; }
inline void chkmax(int& a, int b) { if (a < b) a = b; }

typedef pair<int,int> PII;

const int N = 2000010;
const int INF = 1e18;

int n, a[N], nxt[N], d, c;
PII dp[N];
void solve() {
    cin >> n >> d;
    F(i, 1, n) cin >> a[i];
    F(i,2,n) a[i]-=a[1]; a[1]=0;
    // F(i,1,n)cout<<a[i]<<" ";cout<<"\n";
    F(i,1,n) {
        nxt[i] = -1;
        int l=i,r=n;
        while(l<=r) {
            int mid=l+r>>1;
            if(a[mid] - a[i] <= d)nxt[i]=mid,l=mid+1;
            else r=mid-1;
        }
    }
    // cout<<"nxt : ";
    // F(i,1,n) cout << nxt[i]<<" ";cout<<"\n";
    int res=0;
    F(i, 1, n) {
        F(j, i, n) dp[j] = {INF, 0};
        dp[i] = {0, 1};
        F(j,i,n-1) {
            int t=nxt[j];
            if(t==-1) continue;
            auto upd=[&](int id) {
                if(id<=j) return;
                // cout<<id<<" been updated by "<<j<<" with state ("<<dp[j].first<<", "<<dp[j].second<<") ";
                if(dp[j].first+1<dp[id].first) dp[id].first=dp[j].first+1,dp[id].second=dp[j].second;
                else if(dp[j].first+1==dp[id].first) dp[id].second+=dp[j].second;
            };
            // F(k,1,n)
            // F(k,j+1,nxt[j]) upd(k);
            upd(nxt[j]),upd(nxt[j]-1),upd(nxt[j]-2);
        }
        F(j,i,n) res+=dp[j].second==2;
        // cout<<i<<": ";
        // F(j,1,n) cout << "("<<dp[j].first<<", "<<dp[j].second<<") ";
        //  cout <<"\n";
    }
    cout<<res<<"\n";
}

signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    // freopen("config.txt","r",stdin);
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int T;
    cin >> c >> T;
    while (T -- ) solve();
    return 0;
}