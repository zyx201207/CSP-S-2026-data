#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define pb push_back
const int mo=1e9+7;
ll mod(ll x){
	return (x%mo+mo)%mo;
}
const int N=5e5+5;
int n,m,a[N],sum,ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1,j=1;i<=n&&j<=n;j++){
		if(j>i)sum+=(a[j]-a[j-1])*(j-i);
		while(sum>m){
			sum-=(a[j]-a[i]);
			i++;
		}
		ans=max(ans,j-i+1);
	}
	cout<<ans;
	return 0;
}
