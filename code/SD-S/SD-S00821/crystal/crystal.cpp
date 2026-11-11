#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int inf=1e18,N=1e6+6;
int read()
{
	int x=0,fl=1;char c=getchar();
	while(c!='-'&&(c<'0'||c>'9'))c=getchar();
	if(c=='-'){fl=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	return x*fl;
}
int n,m,num[N],sum[N];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++)
		num[i]=read();
	sort(num+1,num+1+n);
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]+num[i]; 
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int l=1,r=i-1,v=0;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(num[i]*mid-(sum[i-1]-sum[i-mid-1])<=m)
			{
				v=mid;
				l=mid+1;
			}
			else
				r=mid-1;
		}
		ans=max(ans,v+1);
	}
	cout<<ans<<'\n';
	return 0;
}
