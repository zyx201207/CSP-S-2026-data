#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=5e5+5,NN=5e5;
int a[N],ans;
signed main()
{
//	freopen("crystal.in","w",stdin);
//	freopen("crystal.out","t",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n>=NN)
	{
		if(a[1]==1&&a[2]==2)
		{
			for(int i=1;i<=n;i++)
			{
				int sum=(1+i)*i/2;
				if(sum>m)
				{
					cout<<i;
					return 0;
				}
			}
		}
		else
		{
			int flag=a[2]-a[1];
			for(int i=1;i<=n;i++)
			{
				int sum=(a[1]*2+flag*(i-1)*i/2);
				if(sum>m)
				{
					cout<<i-1;
					return 0;
				}
			}
		}
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			int sum=0,cnt=0;
			for(int j=i;j<=n;j++)
			{
				if(j!=i)
				{
					sum+=cnt*(a[j]-a[j-1]);
				}
				if(sum>m)
				{
					ans=max(ans,cnt);
					break;
				}
				cnt++;
			}
		}
	}
	cout<<ans;
	return 0;
}