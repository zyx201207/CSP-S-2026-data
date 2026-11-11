#include <bits/stdc++.h>
using namespace std;
long long n,m,a[5000005],num;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[i]==a[j])
			{
				num++;
			}
			else if(a[j]+m==a[i])
			{
				num++;
			}
		}
	}
	cout<<num/2;
	return 0;
	//分来！分来！分来！ 
}
