#include <bits/stdc++.h>
using namespace std;
int n,m,a[5010],b[3005][5000],num = 1; 
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	
	int sum = 0;
	
	for(int z = 1;z<=n;z++)
	{
		for(int i=z+1;i<=n;i++)
		{
			if(a[z] == a[i])
			{
				int t  = i;
				for(int j = 1;j<=n-i+1;j++)
				{
					b[num][j] =  a[t];
					t++;
				}
				num += 1;
				a[i-1] = -1;
				z = 1;
				continue;
			}
		}
	}
	
	/*
	for(int i = 1;i<=m;i++)
	{
		for(int j = 1;j<=sizeof(b[i]);j++)
		{
			cout<<b[i][j] <<" ";
		}
		cout<<endl;
	}
	*/
	
	
	for(int i = 1;i<=m;i++)
	{
		sum = 0;
		for(int j = 1;j<=sizeof(b[i]);j++)
		{
			if(b[i][j] == 1)
			{
				sum++;
			}
		}
		if (sum != 0) cout<< sum<<" ";
	}
	
	
	
	return 0;
} 
