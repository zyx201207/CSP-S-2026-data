#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int m,n;
int a[N];
int sum=0;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>m>>n;
	int x,y;
	while(n--)
	{
		cin>>x>>y;
		for(int i=1;i<=x;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<=x;i++)
		{
			if(a[i]+y==a[x])
			{
				sum++;
			}
		}
		cout<<sum/2+1;
	}
	return 0;
}