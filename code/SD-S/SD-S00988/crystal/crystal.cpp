#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500001],l=1,r=1,ans=0,nd=0;
int main()
{	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	while(l<=r && r<=n)
	{	if(nd<=m)
		{	r++;
			nd+=(r-l)*(a[r]-a[r-1]);
			ans=max(ans,r-l);
		}
		else
		{	nd-=a[r]-a[l];
			l++;
		}
	}
	cout<<ans;
	return 0;
}
