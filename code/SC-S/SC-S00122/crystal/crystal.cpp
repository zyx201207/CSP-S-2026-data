#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 5e5+10;

ll n,m,ans;
ll a[N],s[N],s2[N];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin >> n >> m;
	bool f2=1,f1=1;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		s2[i] = s2[i-1] + i+1;
	}
	sort(a+1,a+n+1);
	
	for(int i = 1;i <= n;i++)
		s[i] = s[i-1]+a[i];
	for(int i = 3;i <= n;i++)
		if(a[i] != i) f1 = 0;
	for(int i = 3;i <= n;i++)
		if(a[i]-a[i-1] != a[i-1]-a[i-2]) f2 = 0;
	if(f1){
		ll cnt = m / (a[3]-a[2]);
		ll ans = lower_bound(s2+1,s2+n+1,cnt)-s2;
		cout << ans;
		return 0;
	}
	if(f2){
		ll cnt = m / (a[3]-a[2]);
		ll ans = lower_bound(s2+1,s2+n+1,cnt)-s2;
		cout << ans+1;
		return 0;
	}
	for(int i = 1;i <= n;i++){
		ll cnt = 0;
		cnt = i*a[i]-s[i];
		if(cnt <= m) ans = i;
		else break;
	}
	cout << ans;
	return 0;
}
