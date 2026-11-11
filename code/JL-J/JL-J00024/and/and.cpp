#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,c[1001],h=0 ,a[100001],s=0,b[100001];
	cin>>n>>m;
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			cin>>c[i];
			for(int y=1;y<=c[i];y++)
			{
				a[s]=c[i]%2;
				c[i]/=2;
				s++;
				if(c[i]==0)
					break;
					
			}
		}
	}
	for(int y=1;y<=c[i];y++)
	{
		b[s]=a[y];
		s--;
	}
	for(int k=1;k<=c[i];k++)
	{
		cout<<b[k];
	}
	return 0;
}
