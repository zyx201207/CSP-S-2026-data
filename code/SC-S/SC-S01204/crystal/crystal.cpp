#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=5e5+5;
int n,m,a[N],ans;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int j=n,sum=0,last=n;
	for(int i=n;i>=1;i--)
	{
		sum-=(a[last]-a[i])*(i-j+1);
		//cout<<i<<" AAA "<<j<<" "<<sum<<endl; 
		for(j=j-1;j>=1;j--)
		{
			sum+=a[i]-a[j];
			//cout<<i<<" "<<j<<" "<<sum<<endl;
			if(sum>m)
			{
				ans=max(ans,i-j);break;
			}
			if(j==1)
			{
				cout<<i;return 0;
			}
		}
		last=i;
	}
	cout<<ans;
	return 0;
}