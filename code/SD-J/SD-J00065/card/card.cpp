#include<bits/stdc++.h>
using namespace std;
vector<bool> b(300001);
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long int n,m;
	cin>>n>>m;
	vector<long long int> v(n+1);
	vector<long long int> cd(m+1);
	for(long long int i=1;i<=n;i++)
	{
		cin>>v[i];
	}
	for(long long int i=1;i<=n;i++)
	{
		long long int z=i;
		for(long long int u=z;u<=n;u++)
		{
			for(long long int j=u+1;j<=n;j++)
			{
				if(v[z]==v[j])
				{
					for(long long int d=z;d<j;d++)
					{
						b[d]=true;
					}
					z=j;
				}
			}
			u=z+1;
			z=u;
		}
		for(long long int j=i;j<=n;j++)
		{
			if(b[j]==false)
			{
				cd[v[j]]++;
			}
		}
		for(long long int j=i;j<=n;j++) b[j]=false;
	}
	for(long long int i=1;i<=m;i++)
	{
		cout<<cd[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
