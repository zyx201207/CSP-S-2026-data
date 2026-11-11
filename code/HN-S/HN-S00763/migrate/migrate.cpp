#include<bits/stdc++.h>
#define int long long
using namespace std;
const int NR = 2e6 + 5;
struct asdf{
    int l,r;
};
int c,t;
int n,d;
int a[NR];
int r[NR];
asdf k[NR];
int ll[NR];
int rr[NR];
int m;
int ans;
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> t;
    while(t--){
        m = ans = 0;
        cin >> n >> d;
        for(int i = 1;i <= n;i++) cin >> a[i];
        for(int i = 1;i <= n;i++){
            r[i] = max(i,r[i - 1]);
            while(a[r[i]] - a[i] <= d && r[i] <= n) r[i]++;
            r[i]--;
        }
		for(int i = 1;i <= n;i++){
			if(r[i] != r[i - 1]) k[++m] = {i,r[i]};
		}
        k[0] = {(int)-1e9,(int)-1e9};
        k[m + 1] = {(int)1e9,(int)1e9};
        for(int i = 1;i <= m;i++){
            rr[i] = max(i,rr[i - 1]);
            while(k[rr[i]].r == k[rr[i] + 1].l && rr[i] <= m) rr[i]++;
        }
        ll[m + 1] = 1e9;
        for(int i = m;i >= 1;i--){
            ll[i] = min(i,ll[i + 1]);
            while(k[ll[i]].l == k[ll[i] - 1].r && ll[i] >= 1) ll[i]--;
        }
        int r = 1;
        for(int i = 1;i < m;i++){
            r = max(r,i + 1);
            while(k[i].r - k[r].l >= 1) r++;
            r--;
            if(k[i].r <= k[r].l || r <= i) continue;
            if(k[i].r - k[r].l == 1){
				ans += (k[i + 1].l - k[ll[i]].l) * (k[rr[r]].r - k[r - 1].r);
			}
        }
        cout << ans << "\n";
    }
    return 0;
}