#include<bits/stdc++.h>
using namespace std;
int n,l,r,mid;
long long m,s[500010],a[500010];
int check(int x){
	long long MIN=1e18;
	for(int i=x;i<=n;++i)MIN=min(MIN,a[i]*x-s[i]+s[i-x]);
	return MIN<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i)s[i]=s[i-1]+a[i];
	r=n+1;
	while(l+1<r){
		mid=l+r>>1;
		if(check(mid))l=mid;
		else r=mid;
	}
	cout<<l<<"\n";
	return 0;
}
