#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500010],ans;
bool check(ll mi,ll ni){
	ll c=0;
	for(ll i=mi;i>=ni;i--){
		c+=(a[mi]-a[i]);
	}
	if(c>m) return 0;
	else return 1;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;++i){
		for(ll j=1;j<=i;++j){
			if(check(i,j)){
				ans=max(ans,i-j+1);
			}
		}
	}
	cout<<ans;
	return 0;
}
