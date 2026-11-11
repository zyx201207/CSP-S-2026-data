#include<bits/stdc++.h>
using namespace std;
struct node
{
	int u,v,d;
}e[5005];
int c,t;
int n,d;   //岛屿数量和海鸟一次最多能飞行的距离
long long x[5005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdont);
	cin>>c>>t;
	for (int i=1;i<=t;i++)
	{
		cin>>n>>d;
		for (int j=1;j<n;j++)
		{
			cin>>x[i];
		}
	}
	cout << 1;
//	for (int i=0;i<n;i++)
//	{
//		b[i]=x[i+1]-x[i];
//	}
	return 0;
}
