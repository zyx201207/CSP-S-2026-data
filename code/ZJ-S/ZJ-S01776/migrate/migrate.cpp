#include<bits/stdc++.h>
using namespace std;
long long C,T,n,d,a[2000010],f[2000010];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>C>>T;
	while(T--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		int s=0;
		for(int i=1;i<=n;i++)
		{
			memset(f,0,sizeof f);
			f[i]=1;
			for(int j=i+1;j<=n;j++)
			{
				int k=j-1;
				while(a[j]-a[k]<=d&&k>=i&&f[j]<=3)f[j]+=f[k--];
			}
			for(int i=1;i<=n;i++)if(f[i]==3)s++;
		}
		cout<<s<<'\n';
	}
	return 0;
}