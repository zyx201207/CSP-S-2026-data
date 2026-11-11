#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],t,b[500005],l,r;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;t=1;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) b[i]=b[i-1]+a[i];
	l=1;r=1;
	while(l<=r && r<=n){
		if((r-l)*a[r]-b[r-1]+b[l-1]<=m){
			t=max(t,r-l+1);
			r++;
		}
		else l++;
	}
	cout<<t;
	return 0;
}
