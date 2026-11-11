#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int a[200010];
char c[200010];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	int r=n;
	int ans=0;
	for(int i=1;i<n;i++)
	{
			int op=a[i];
			while(op)
			{
				if(c[r]!=c[i])
				{
					ans+=min(a[r],op);
				}
				int rr=a[r];
				a[r]-=min(a[r],op);
				op-=min(rr,op);
				if(a[r]==0)
				r--;
				if(i==r)
				{
					cout<<ans;
					return 0;
				 } 
			}
	}
	cout<<ans;
	return 0;
 } 
