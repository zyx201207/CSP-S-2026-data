#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[200010];
char c[200010];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long ans=0;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>c[i];
	int lm=1,rm=n;
	while(lm<rm)
	{
		if(a[lm]==0)
			lm++;
		if(a[rm]==0)	
			rm--;
		if(c[rm]!=c[lm])
			ans+=min(a[rm],a[lm]);
		int f=min(a[rm],a[lm]);
		a[lm]-=f;
		a[rm]-=f;
	} 
	cout<<ans;				 
	return 0;
}
