#include<bits/stdc++.h>
using namespace std;
const int N=5e5;
long long c,n,m,d,q,x,y,sum,p,f1;
long long w[N+10],k[510],a[501][N+10],t[501][N+10];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
		}
	}
	while(q--)
	{
		cin>>x>>y;
		int p=x;
		sum=0,f1=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=k[i];j++)
			{
				if(a[i][j]=p)
				{
					sum+=w[i]+t[i][j]+t[i][j+1];
					p=a[i][j+1];
				}
				if(p==y)
				{
					f1=1;
					break;
				}
			}
			if(f1==1)
			{
				break;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
