#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 5e5+5;
ll n,m;
ll a[N],b[N],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out ","w",stdout);
	cin >> n >> m;
	for(ll i = 1;i<=n;i++)	cin >> a[i];
	sort(a+1,a+1+n);
	for(ll i = 1;i<n;i++)	b[i] = a[i+1]-a[i];	
	ll l = 1,r = 1,sum = b[1];
	while(r<n){
		if(sum<=m){
			ans=max(r-l+2,ans);
			r++;
			sum+=b[r];
		}else{
			sum-=b[l];
			l++;
		}
		if(l>r)	r++,sum+=b[r];
	}
	cout << ans << '\n';
	return 0;
}
