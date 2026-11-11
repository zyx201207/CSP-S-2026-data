#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int a[N],n,pr[N],m;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)pr[i]=a[i]+pr[i-1];
	int ma=0,l=1,r=1;
	while(r<=n)
	{
		if(a[r]*(r-l+1)-(pr[r]-pr[l-1])<=m)r++,ma=max(ma,r-l);
		else l++;
	}
	cout<<ma;
	return 0;
}