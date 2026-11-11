#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],s[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	for(int i=0;i<n;i++) s[i+1]=s[i]+a[i];
	int ans=0;
	int l=0;
	for(int r=0;r<n;r++)
	{
		while(l<=r)
		{
			long long c=r-l+1;
			long long cs=c*a[r]-(s[r+1]-s[l]);
			if(cs>m) l++;
			else break;
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
