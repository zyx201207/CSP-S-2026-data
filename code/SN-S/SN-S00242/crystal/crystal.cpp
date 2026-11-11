#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ull N = 5e6+10;
ull n, m;
ll a[N];
ull ans = 0;
bool check(ull i)
{
	if(i>n) return false;
	// 返回让i个水晶能量值变为相同的操作能否实现
	ull ret = 0;
	for(ull j=1;j<=i;j++){
		ret += a[i]-a[j];
	}
	
//	cout << "check(" << i << ")     return : " << (ret<=m) << "\n";
//	cout << "    a[" << i << "] = " << a[i] << "\n";
//	cout << "    ret = " << ret << "\n";
	if(ret <= m) return true;
	return false;
}
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(ull i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1, a+n+1);
	
//	int now = 0;
//	for(int i=1;i<=n;i++){
//		if(a[i] != a[i-1]){
//			cout << a[i-1] << " : a[" << now << " ~ " << i-1 << "] " << i-now << "个\n";
//			now = i;
//		}
//	}
//	cout << "\n\n\n";

//	check(315275);
//	cout << "\n\n\n";
	
//	ll x=0;
//	for(int i=1;i<=315275;i++){
//		x += a[i];
//	}
//	cout << x << "\n\n\n";

	for(ull i=1LL<<50;i>0;i>>=1){
		if(check(ans + i))
		{
//			cout << "ans = " << ans << "           ans += " << i << " = " << ans+i << "\n";
			ans += i;
		}
	}
	cout << ans << "\n";
	return 0;
}
