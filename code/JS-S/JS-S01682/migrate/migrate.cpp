#include<bits/stdc++.h>
using namespace std;
int t,c,n;
long long d,a[2000005],f[2000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>t>>c;
	for(int i=1;i<=c;++i)
	{

		cin>>n>>d;
		for(int j=1;j<=n;++j)
		{
			cin>>a[j];
		}
		int s=a[2]-a[1];
		int cnt=d/s;
		f[1]=1;
		f[2]=1;
		for(int j=3;j<=n;++j)
		{
			f[j]=0;
			for(int z=j-1;z>=min(1,z-cnt);--z)
			{
				f[j]+=f[z];
			}
		}
		cout<<f[n]<<endl;
	}
	return 0;
}
