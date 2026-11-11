#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,t,t1,t2;
int n,ans;
ll l;
ll a[2000010],k[2000010];
int up_b(int x)
{
	int l=1,r=n;
	while(l<r)
	{
		int mid=(l+r)>>1;
		if(a[mid]<=a[x])
			l=mid+1;
		else
			r=mid-1;
	}
	return l-1;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>l;
		ans=0,t1=0,t2=0;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(int i=1;i<=n;i++)
		{
			int x=up_b(i);
			k[i]=up_b(i)-i;
		}
		for(int i=1;i<=n;i++)
		{
			if((k[i]!=1&&k[i-1]==k[i])&&(!((k[i]==t2)&&(k[i]+t1>i))))
				ans++,t1=i,t2=k[i];
		}
		cout<<ans<<'\n';
	}
	return 0;
}

