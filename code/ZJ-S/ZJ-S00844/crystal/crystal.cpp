#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=5e5+5;
int n,m,a[N],add[N];
int read()
{
	int a=0,b=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-') b*=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		a=a*10+c-'0';
		c=getchar();
	}
	return a*b;
}
bool check(int cur,int bil)
{
	int hope=a[cur]*(cur-bil),bad=add[cur-1]-add[bil-1];
	if(hope-bad<=m) return 1;
	else return 0;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
	}
	sort(a+1,a+n+1);
	add[1]=a[1];
	for(int i=2;i<=n;i++)
	{
		add[i]=add[i-1]+a[i];
	}
	int ans=-1;
	for(int i=1;i<=n;i++)
	{
		int l=1,r=i;
		while(l<=r)
		{
			int mid=l+(r-l)/2;
			if(check(i,mid))
			{
				r=mid-1;
				ans=max(ans,i-mid+1);
			}
			else
			{
				l=mid+1;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}