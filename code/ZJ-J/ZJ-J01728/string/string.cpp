#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[200100];
char b[200100];
signed main(void)
{
	
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
	}
	int l=1,r=n,ans=0;
	while(l<r)
	{
		int k=min(a[l],a[r]);
	    a[l]-=k;
		a[r]-=k;
		if(b[l]!=b[r])
		{
			ans+=k;
		}
		
		if(a[l]==0) l++;
		if(a[r]==0) r--;
		
	}
	cout<<ans;
	return 0;
}