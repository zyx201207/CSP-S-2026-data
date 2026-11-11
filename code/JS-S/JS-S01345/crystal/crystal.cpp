#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;
ll m,tmp;
ll a[500005];
bool cmp(ll x,ll y){
	return x>y;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=2;i<=n;i++){
		tmp+=abs(a[1]-a[i]);
	}
	if(tmp<=m){
		cout<<n;
		return 0;
	}
	for(int i=2;i<=n;i++){
		tmp-=(n-i+1)*(a[i-1]-a[i]);
		if(tmp<=m){
			cout<<(n-i+1);
			return 0;
		}
	}
	return 0;
}
