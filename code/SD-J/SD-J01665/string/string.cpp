#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],ans;
char c[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>c[i];
	long long l=1,r=n;
	while(1)
	{
		if(l>=r)
			break;
		long long lose=min(a[l],a[r]);
		if(c[l]!=c[r])
			ans+=lose;
		a[l]-=lose;
		a[r]-=lose;
		if(a[l]==0)
			l++;
		if(a[r]==0)
			r--;
	}
	cout<<ans;
	return 0;
 } 
