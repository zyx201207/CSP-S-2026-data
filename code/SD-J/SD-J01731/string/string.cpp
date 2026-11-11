#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,a[N],sum,sum2,ans;
char x[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>x[i];
		sum+=a[i];
	}
	long long l=1,r=n;
	while(sum>0)
	{
		if(a[l]==0)l++;
		if(a[r]==0)r--;
		if(x[l]!=x[r])
		{
			
			ans+=min(a[l],a[r]);
		}
		sum-=min(a[l],a[r])*2;
		int t=min(a[l],a[r]);
		a[l]-=t,a[r]-=t;
	}
	cout<<ans;
	return 0;	
} 
