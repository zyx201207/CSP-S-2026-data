#include<bits/stdc++.h>
using namespace std;
int n;
int m;
int a[500005];
long long b[300005];

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		b[a[i]]++;
	}
	for(int i=1;i<=m;i++)
	{
		cout<<b[i]<<' ';
		b[i+1]+=b[i];
	}
	return 0;
}
