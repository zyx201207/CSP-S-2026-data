#include<bits/stdc++.h>
using namespace std;
int n,ans;
long long m,a[500005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=n;i>1;i--)
	{
		long long s=0;
		for(int j=1;j<i;j++)
		{
			s+=a[i]-a[j];
		}
		if(s<=m)
		{
			for(int j=n;j>=i;j--)
			{
				if(a[j]==a[i])
				{
					cout<<j;
				}
			}
			break;
		}
	}
	
	return 0;
} 
