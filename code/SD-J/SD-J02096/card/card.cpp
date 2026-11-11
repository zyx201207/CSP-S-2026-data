#include<bits/stdc++.h>
using namespace std;
int n, m;
int a[5005]={0};
int m2[3005]={0};
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i=0; i<n; i++)
		cin >> a[i];
	for(int i=0; i<n; i++)
	{
		for(int j=i; j<n; j++)
		{
			for(int k=j-1;k>=i; k--)
			{
				if(a[j]==a[k])
				{
					for(int l=k+1;l<=j; l++)
						a[l]=0;
				}
			}
		}
		bool m3[3005]={false};
		for(int x=0; x<n; i++)
		{
			if(a[x]>=0&&m3[a[x]]==false)
			{
				m2[a[x]]++;
				m3[a[x]]=true;	
			}
		}
	}
	for(int i=1; i<=m; i++)
		cout << m2[i];
	return 0;
}
