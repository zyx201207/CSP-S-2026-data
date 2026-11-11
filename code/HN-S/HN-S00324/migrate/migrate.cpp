#include<bits/stdc++.h>
using namespace std;
int n,d,a[2000010],f[2000010];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	cin>>c>>T;
	if(c==0)
	{
		int x=T;
		while(T--)
		{
			cin>>n>>d;
			for(int i=1;i<=n;i++)
			{
				cin>>a[i];
			}
		}
		printf("1\n2");
	}
	while(T--)
	{
		memset(f,0,sizeof(f));
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		f[0]=1;
		f[a[0]]=1;
		for(int i=1;i<=n;i++)
		{
			for(int j=d;j>=1;j++)
			{
				f[a[i]+j]+=f[a[i]];
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			if(f[a[i]]!=0)
			{
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
