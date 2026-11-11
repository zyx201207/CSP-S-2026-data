#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m,s,a[N],b[N],ans=1;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<n;i++)
	{
		b[i]=a[i+1]-a[i];
		s+=a[n]-a[i];
	}
	for(int i=n;i>=1;i--)
	{
		s-=i*b[i];
		if(s<=m) ans=max(ans,i);
		else
		{
			int t=s;
			for(int j=1;j<i;j++)
			{
				t-=a[i]-a[j];
				if(t<=m) 
				{
					ans=max(ans,i-j);
					break;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}