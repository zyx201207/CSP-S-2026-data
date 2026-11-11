#include<bits/stdc++.h>
using namespace std;
char a[100000005],c[100000005],C[100000005];
int n,cnt;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		for(int i=1;i<=a[i];i++)
		{
			C[i]+=c[i];
			C[i]*=10;
		}
		C[i]/=10;
	}
	for(int i=n;i>=1;i--)
	{
		c[i]=C[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(c[i]!=C[i])
		{
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}