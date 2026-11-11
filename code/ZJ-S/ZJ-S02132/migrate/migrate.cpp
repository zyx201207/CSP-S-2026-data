#include<bits/stdc++.h>
using namespace std;
int n,x[1000001],d;
int find(int a,int b)
{
	int ans=0,f[500005][500005];
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;i++) f[i][i]=0;
	for(int i=a+1;i<=b;i++)
	{
		for(int j=a;j<i;j++)
		{
			if(x[i]-x[j]<=d) f[j][i]=min(f[a][j]+1,f[j][i]);
		}
	}
	int minn=f[a][b];
	for(int i=a+1;i<=b;i++)
	{
		if(f[a][i]+f[i+1][b]==minn) ans++;
	}
	return ans;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t)
	{
		--t;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		long long cnt=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(find(i,j)>=2) cnt++;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
