#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.ans","w",stdout);
	const long long N=1e14;
    int a [N];
	int cnt=0,x,n;
	char y;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>y;
		for(int j=1;j<=x;j++)
		{
			a[j]==y;
		}
	}
	for(int i=1;i<=n/2;i++)
	{
		if(a[i]!=a[n/2*2-i])
		{
			cnt++;
		}
	}
	cout<<cnt;
}
