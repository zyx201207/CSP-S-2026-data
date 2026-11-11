#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 5;
long long a[MAXN], sum[MAXN];
map<long long, long long> mp;
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    long long n, m;
    cin >> n >> m;
    long long ans = 0;
    for(long long i = 1; i <= n; i++){
        cin >> a[i];
        mp[a[i]]++;
        if(mp[a[i]] > 1) ans = max(ans, mp[a[i]]);
    }
    sort(a + 1, a + 1 + n);
    sum[0] = 0;
    sum[1] = a[1];
    long long t = 0;
    for(long long i = 2; i <= n; i++){
        sum[i] = sum[i - 1] + a[i];
        while(1LL * (i - t) * a[i] - sum[i] + sum[t] > m){
			t++;
		}
        if(1LL * (i - t) * a[i] - sum[i] + sum[t] <= m){
            ans = max(ans, i - t);
        }
    }
    cout << ans;
    return 0;
}
