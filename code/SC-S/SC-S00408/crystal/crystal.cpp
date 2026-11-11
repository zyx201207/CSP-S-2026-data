#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=5e5+5;
ll a[maxn],m,ans,prf[maxn];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		prf[i]=prf[i-1]+a[i];
	}
	ll l=1,r=1;
	while(r<=(ll)n){
		ll k=(r-l+1)*a[r]-(prf[r]-prf[l-1]);
		if(k<=m){
			ans=max(ans,r-l+1);
			r++;
		}else{
			l++;
		}
	}
	cout<<ans;
	return 0;
}