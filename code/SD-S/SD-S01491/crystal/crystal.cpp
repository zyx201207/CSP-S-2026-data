#include<bits/stdc++.h>
using namespace std;
long long a[500005],s[500005],n,m;
int ans;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]+a[i];
	int j=1;
	for(int i=1;i<=n;i++)
	{
		while((i-j)*a[i]-s[i-1]+s[j-1]>m)
			j++;
		ans=max(ans,i-j+1);
	}
	cout<<ans;
	return 0;
 } 
