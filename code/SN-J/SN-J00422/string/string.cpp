#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string a,g;
	long long cnt=1;
	long long c[10005];
	int b;
	cin>>b;
	for(int i=1;i<=b;i++)
	{
		cin>>c[i];
		cin>>a[i];
	}
	for(int i=1;i<=b;i++)
	{
		for(int j=1;j<=c[i];j++)
		{
			g[cnt]=a[cnt];
			cnt++;
			cout<<g[cnt];
		}
	}
	

	long long r=cnt;
	cnt=0;
	for(int i=0;i<r;i++)
	{
		
		for(int j=r;j>=1;j--)
		{
			if(g[j]!=g[i])
			{
				cout<<a[i];
				g[j]=g[i];
				cnt++;	
			}
		}
	}
	cout<<cnt-1;
	return 0;
}
