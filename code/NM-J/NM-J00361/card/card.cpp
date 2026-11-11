#include<bits/stdc++.h>
using namespace std;
long long b[200005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
	int m,n;
	cin>>m>>n;
	for(int i=0;i<m;i++)
	{
		cin>>b[i];
	}
	int f[200005];
	for(int i=0;i<m;i++)
	{
		int v[200005];
		for(int j=0;j<m;j++)
		{
			v[j]=b[j];
		}
		int y=i;
		for(int j=i;j<m;j++)
		{
			if(v[j]==v[y])
			{
				for(int l=y;l<j;l++)
				{
					v[l]=0;
					y=j;
				}
			}
		}
		for(int j=i;j<m;j++)
		{
			cout<<v[j]<<" ";
		}
		cout<<endl;
		for(int j=i;j<m;j++)
		{
			if(v[j]!=0)
			{
				f[v[j]]++;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		cout<<f[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
