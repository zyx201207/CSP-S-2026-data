#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long int n,m,a[N],t,maxx,g,d;
string a1,b1;
int rjz(long long int x)
{
	d=0;
	while(x>0)
	{
		d+=x%2;
		d*=10;
		x/=2;
	}
	return d;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j=n;j++)
		{
			for(int k=1;k<=n;k++)
			{
				g=rjz(a[j])&rjz(a[k]);
				maxx=max(maxx,g);
			}
		}
	}
	cout<<maxx;
	return 0;
}