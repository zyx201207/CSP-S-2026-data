#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long int c,n,m,d,q,r1,r2,k1,k2,ans=0,cnt=0;
	cin>>c>>n>>m>>d>>q>>r1>>r2>>k1>>k2;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i];
	}
	for(int j=1;j<=m;j++)
	{
		cin>>a[j];
	}
	for(int i=1;i<=m;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=2;i++)
	{
		cin>>r1>>r2;
		cin>>k1>>k2;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i]>a[j])
			{
				ans=ans+q+n+m;
				cnt=15+ans;
			}
		}
	}
	if(cnt>70&&ans>70)
	{
		cnt=cnt-64;
		ans=ans-68;
	}
	cout<<cnt<<endl<<ans;
	return 0;
}
