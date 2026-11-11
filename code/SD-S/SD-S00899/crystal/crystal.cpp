#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#include<cstdio>
#include<string>
using namespace std;
#define int long long
const int N=5e5+10; 
int n,m,a[N],f[N],g[N],ans,s[N];
bool check(int i,int j)
{
	int x=j-f[j]+1,y=i-1;
	int res=a[j]*(y-x+1)-s[y]+s[x-1];
	if(res+g[j]>=0)
	{
		return 1;
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	g[0]=m;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		s[i]=a[i]+s[i-1];
	}
	for(int i=1;i<=n;i++)
	{
		g[i]=g[i-1]-max(f[i-1]-1,0ll)*(a[i]-a[i-1]);
		f[i]=f[i-1]+1;
		int l=i-f[i]+2,r=i;
		if(g[i]<0)
		{
			while(l<=r)
			{
				int mid=l+r>>1;
				if(check(mid,i))
				{
					r=mid-1;
				}
				else
				{
					l=mid+1;
				}
			}
			f[i]=f[i]-(l-1-(i-f[i]+1))-1;
			g[i]=m-(a[i]*(f[i]-1)-s[i-1]+s[i-f[i]]);
		}
		ans=max(ans,f[i]);
	}
	cout<<ans;
	return 0;
}
