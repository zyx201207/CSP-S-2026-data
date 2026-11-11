#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=500010;
ll n,m;
ll a[MAXN],s[MAXN];
ll ans = 1;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i]; 
	}
	sort(a+1,a+n+1);
	if (n>5000) {
		ll d = a[2]-a[1];
		while((d*ans*(ans-1)<=2*m)&&(ans<=n)) ans++;
		cout<<ans-1<<endl;
		return 0;
	}
	for (int i=1;i<=n;i++){
		s[i] = s[i-1] + a[i];
	}
	
	for (int i=2;i<=n;i++){
		ll cnt = i;
		while (cnt>1){
			if(cnt*a[i]-(s[i]-s[i-cnt])<=m) break;
			cnt--;
		}
		ans = max(ans,cnt);
	}
	cout<<ans<<endl;
	return 0;
}
