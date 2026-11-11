#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+8;
int a[N],num[N],s[N];

int q(int i,int j)//求i-j区间和 
{
	return s[j]-s[i-1];
}

signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m,cnt=0,ans=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		s[i]=s[i-1]+a[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(num[cnt]!=a[i])
		{
			cnt++;
			num[cnt]=a[i];
		}
	}
	for(int i=1;i<=n;i++)
	{
		int l=i,r=n+1;
		while(l<r)
		{
			int mid=(l+r)/2,p=mid-i+1,tot=a[mid]*p,tgt=q(i,mid),x=tot-tgt;
			
			if(x>m)
			{
				r=mid;
			}
			else
			{
				ans=max(ans,p);
				l=mid+1;
			}
		} 
	}
	cout<<ans;
	return 0;
}
