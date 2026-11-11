#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;
ll a[500010],s[500010];
bool check(int x){
	x--;
	for(int i=1;i<=n-x;i++){
		if((s[i+x]-s[i])-(i-1)*(a[i+x]-a[i])<=m)return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		s[i]=(i-1)*(a[i]-a[i-1])+s[i-1];
	}
	ll l=0,r=n;
	while(l<r){
		ll mid=(l+r+1)/2;
		if(check(mid)){
			l=mid;
		}
		else r=mid-1;
	}
	cout<<l;
	return 0;
}
