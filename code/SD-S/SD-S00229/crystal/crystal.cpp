#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll m,a[N],d[N],num[N];
ll n,ans=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(ll i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+1+n);
	ll j=1;
	d[1]=1; d[0]=0;
	num[1]=num[0]=0;
	for(ll i=2;i<=n;i++){
		num[i]=num[i-1]+(a[i]-a[i-1])*(i-1);
		while(num[i]-(a[i]-a[j])*(j-1)-num[j]>m&&j<i){
			j++;
		}
		d[i]=i-j+1;
		
		ans=max(ans,d[i]);
	}
	cout << ans;
	return 0;
}
