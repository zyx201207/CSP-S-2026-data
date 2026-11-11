#include<bits/stdc++.h>
using namespace std;
const int N=5e5+8;
long long a[N],m,sum;
int n,ans;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	ans=0;
	for(int i=2;i<=n;i++)
	{
		long long line=a[i],lm=m;
		int cnt=1;
		for(int j=i-1;j>=1;j--)
		{
			if(lm-(line-a[j])>=0) 
			{
				lm-=(line-a[j]);
				cnt++;
			}
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
} 
