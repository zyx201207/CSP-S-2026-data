#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=500005;
int n;
ll a[N],m,pfs[N];
int ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		pfs[i]=pfs[i-1]+a[i];
	for(int i=n;i>=1;i--)
		while(i-ans>0&&a[i]*(ans+1)-pfs[i]+pfs[i-(ans+1)]<=m)
			ans++;
	cout<<ans;
	return 0;
}