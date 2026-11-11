#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 2010;
const int mod = 998244353;
int c,n,d,x[MAXN],ans[MAXN][MAXN];
bool ok[MAXN][MAXN];
void solve(){
    cin >> n >> d;
    memset(ans,0,sizeof(ans));
    memset(ok,false,sizeof(ok));
    for(int i = 1;i <= n;i++) cin >> x[n];
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            if(abs(x[i] - x[j]) <= d) ok[i][j] = ok[j][i] = true;
        }
    }
    for(int i = 3;i < (1 << 10);i++){
        int a[10];
        int cnt = 0;
        for(int j = 1;j <= n;j++){
            if(i & (1 >> (n - 1))) a[++cnt] = j;
        }
        do{
            bool okk = true;
            for(int i = 1;i < cnt;i++){
                if(!ok[a[i]][a[i + 1]]) okk = false;
            }
            if(okk) ans[a[i]][a[i + 1]]++,ans[a[i + 1]][a[i]]++;
        }while(next_permutation(a + 1,a + cnt + 1));
    }
    int res = 0;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            if(ans[i][j] == 2) res++;
        }
    }
    cout << res << endl;
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
	int t = 1;
	cin >> c >> t;
	while(t--) solve();
	return 0;
}
