#include<bits/stdc++.h>
using namespace std;
long long n,a[500005],pre[500005],m,ans;
int check(int l,int r)
{
	long long tot=a[r]*(r-l)-pre[r-1]+pre[l-1];
	if(tot>m)
	return 0;
	else
	return 1;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	} 
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	pre[i]=pre[i-1]+a[i];	
	for(int i=1;i<=n;i++)
	{
		long long l=0,r=i+1,mid,k;
		while(l+1<r)
		{
			mid=(l+r)/2;
			if(check(mid,i)==1)
			{
				r=mid;
				k=mid;
			}
			else
			l=mid;
		}
		ans=max(ans,i-k+1);
	}
	cout<<ans;
	return 0;
}
