#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,tot,ans=1;
int a[N],s[N];
int energy[N];
signed main()
{
	//freopen("test.in","r",stdin);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		s[i]=s[i-1]+a[i];
		energy[i]=energy[i-1]+(a[i]-a[i-1])*(i-1);
	}
	s[0]=0;
	a[0]=0;
	int l=1,r=1;
	while(r<=n)
	{
		int star=energy[r]-(a[r]*(l-1)-s[l-1]);
		if(star<=m)
		{
			ans=max(ans,r-l+1);
			r++;
		}
		else
		l++;
		if(l>r)r=l;
	}
	cout<<ans;
	return 0;
}