#include<bits/stdc++.h>
using namespace std;
int w[5005],k[501],d,f,a[501][5000],t[501][5000];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q,sum=0;
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
	for(int i=1;i<=n;i++)
	{
		cin>>d>>f;
		for(int j=d;j<=f;j++)
		{
			for(int l=1;l<=n;l++)
			{
				for(int z=1;z<=k[l];z++)
				{
					if(a[l][z]==j)
					{
						sum+=t[l][z];
					}
				}
			}
		}
		sum=sum+w[d]+w[f];
		cout<<sum<<endl;
		sum=0;
	}
	return 0;
}
