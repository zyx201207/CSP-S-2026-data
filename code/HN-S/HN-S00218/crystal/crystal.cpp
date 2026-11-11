#include<bits/stdc++.h> 
#define int long long
using namespace std;
int n,m,s[500005],a[500005],ans=0;
int check(int x,int id)
{
	int num=s[id]-s[id-x],num2;
	num2=x*a[id];
	num2-=num;
	return num2;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i = 1;i<=n;i++)
	{
		cin>>a[i];
		
	}
	sort(a+1,a+n+1);
	for(int i = 1;i<=n;i++)
	{
		
		s[i]=s[i-1]+a[i];
	}
	
	for(int i = 1;i<=n;i++)
	{
		int l=1,r=i;
		//cout<<i<<endl;
		while(l+1<r)
		{
			int mid=(l+r)/2;
			if(check(mid,i)>m)
			{
				
				r=mid;
				//cout<<"r"<<r<<endl;
			}
			else
			{
				
				l=mid;
				//cout<<"l"<<l<<endl;
			}
		}
		if(check(r,i)<=m)
		{
			ans=max(ans,r);
		}
		else
		{
			ans=max(ans,l);
		}
		
		
		
	}
	cout<<ans<<endl;
	return 0;
}
