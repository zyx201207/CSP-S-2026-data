#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],s[N];
bool check(int x){
	for(int i=x;i<=n;i++)
		if(a[i]*x-(s[i]-s[i-x])<=m)
			return 1;
	return 0;
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	int l=1,r=n;
	while(l<r){
		int d=(l+r+1)>>1;
		if(check(d))l=d;
		else r=d-1;
	}
	cout<<l;
	return 0;
}