#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500005];
int c[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n+1);
	if(n<=5000)
	{
		int ans=0;
		for(int i=n;i>=1;i--)
		{
			int cnt=1;
			int tmp=m;
			for(int j=i-1;j>=1;j--)
			{
				if(tmp<a[i]-a[j])
				{
					break;
				}
				else
				{
					tmp-=(a[i]-a[j]);
					cnt++;
				}			
			}
			ans=max(ans,cnt);
		}
		cout<<ans;
		return 0;
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			c[i]=a[n]-a[i];
		}
		int ans=0;
		int l=1,r=2;
		int tmp=c[1]-c[2];
		while(r<=n)
		{
			if(r==l)
			{
				r++;
				tmp=c[l]-c[r];
			}
			else if((tmp+(c[r-1]-c[r])*(r-l))<=m)
			{
				tmp+=(c[r-1]-c[r])*(r-l);
				ans=max(ans,r-l+1);
				r++;
			}
			else
			{
				tmp-=(c[l]-c[r]);
				l++;
			}
		}
		cout<<ans;
	}
	return 0;
}
