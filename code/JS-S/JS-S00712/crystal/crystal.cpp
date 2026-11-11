#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 500010;
const int mod = 998244353;
int n,m,sum[MAXN],v[MAXN],a[MAXN],b[MAXN];
int cnt = 0;
int check(int x){
    int res = 0,mm = m;
    // << "x:" << x << endl;
    int st = lower_bound(a + 1,a + cnt + 1,x) - a - 1;
    for(int i = st;i >= 1;i--){
        if((x - a[i]) == 0) continue;
        int l = mm / (x - a[i]);
        int k = min(b[i],l);
        //cout << a[i] << " " << k << endl;
        mm -= k * (x - a[i]);
        res += k;
    }
    return res + b[st + 1];
}
bool check1(){
    bool ok = true;
    if(n == 1) return ok;
    for(int i = 2;i <= cnt;i++){
        if(a[i] - a[i - 1] != a[2] - a[1]) ok = false;
    }
    return ok;
}
void solve(){
    cin >> n >> m;
    map<int,int> mp;
    for(int i = 1;i <= n;i++){
        int a;
        cin >> a;
        mp[a]++;
    }
    for(auto i:mp) a[++cnt] = i.first,b[cnt] = i.second;
    if(check1()){
        int sum = 0;
        for(int i = 2;i <= n;i++){
            sum += a[i] - a[i - 1];
            if(sum > m){
                cout << i - 1 << endl;
                return;
            }
        }
        cout << n << endl;
        return;
    }
    //int l = a[1],r = a[cnt];
    int ans = 0;
    for(int i = 1;i <= cnt;i++){
        ans = max((int)check(a[i]),ans);
    }
    cout << ans << endl;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
	int t = 1;
	//cin >> t;
	while(t--) solve();
	return 0;
}
