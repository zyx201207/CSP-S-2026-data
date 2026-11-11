#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;long long m;cin>>n;cin>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);	
	int ans=1,l=0,sum=1;
	long long mnow=0;
	for(int i=1;i<n;i++)
	{
		mnow=mnow+sum*(a[i]-a[i-1]);
		sum++;
		if(mnow>m)
		{
			while(mnow>m&&sum)
			{
				sum--;
				mnow=mnow-a[i]+a[l];
				l++;
			}
		}
		ans=max(ans,sum);
	}
	cout<<ans;
	return 0;
}
