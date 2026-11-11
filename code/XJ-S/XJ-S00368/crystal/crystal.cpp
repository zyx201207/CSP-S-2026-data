#include<bits/stdc++.h>
using namespace std;
#define int long long  
const int N=5e3+10;
int n,m,ans=1,num[500010],f[N][N],sum[N][N],maxn[N][N];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	cin>>n>>m;
	if(n>5000)
	{
		for(int i=1;i<=n;i++)
			cin>>num[i];
		sort(num+1,num+1+n);
		int a=num[1],t=num[2]-num[1];
		for(int x=sqrt(2*m/t+1000);;x--)
			if(x*(x-1)*t<=2*m)
			{
				cout<<x;
				return 0;
			}
	}
	for(int i=1;i<=n;i++)
		cin>>num[i];
	sort(num+1,num+1+n);
	for(int i=1;i<=n;i++)
		sum[1][i]=sum[1][i-1]+num[i];
	for(int i=2;i<=n;i++)
		for(int j=i;j<=n;j++)
			sum[i][j]=sum[i-1][j]-num[i-1];
	for(int i=1;i<=n;i++)
		maxn[i][i]=num[i];
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			maxn[i][j]=max(maxn[i][j-1],num[j]);
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		{
			f[i][j]=(j-i+1)*maxn[i][j]-sum[i][j];
			if(f[i][j]<=m&&(j-i+1)>ans)
				ans=j-i+1;
		}
	cout<<ans<<'\n';
	return 0;
}
