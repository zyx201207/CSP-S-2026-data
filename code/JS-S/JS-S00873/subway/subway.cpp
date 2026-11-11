#include <bits/stdc++.h>
using namespace std;
int w[1000005], a[3][1000005], t[3][1000005];
int main()
{
	int c, n, m, d, q;
	cin>>c>>n>>m>>d>>q;
	int sum=0;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	int k;
	cin>>k;
	for(int i=1;i<=1+2*k;i++)
	{
		cin>>a[1][i]>>t[1][i];
		sum+=a[1][i]+t[1][i];
	}
	for(int i=1;i<=1+2*k;i++)
	{
		cin>>a[2][i]>>t[2][i];
		sum+=a[2][i]+t[2][i];
	}
	int x1, y1, x2, y2;
	cin>>x1>>y1>>x2>>y2;
	cout<<sum;
}
