#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read()
{
	int x=0,y=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')y=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=x*10+(c-'0');
		c=getchar();
	}
	return x*y;
}
const int N=5e5+7;
int a[N];
int cha[N];
int pre[N];
int n;
int m;
struct node
{
	int num;
	int xp;
}e[N];
bool cmp(node x,node y)
{
	return x.num>y.num;
}
int bl[N];
int ak(int l,int r)
{
	return bl[r]-bl[l-1]-(pre[r]-pre[l-1])*(l-1);
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	bool f=0;
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		if(a[i]<a[i-1]&&i>=2)f=1;
	}
	if(n<=500)
	{
		int ans=0;
		for(int i=1;i<=n-1;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				int sum=0;
				int maxn=0;
				
				for(int k=i;k<=j;k++)
				{
					maxn=max(maxn,a[k]);
					
				}
				for(int k=i;k<=j;k++)
				{
					sum+=(maxn-a[k]);
				}
				if(sum<=m)ans=max(ans,j-i+1);
			 } 
		}
		cout<<ans<<endl;
		return 0;
	}
	if(!f)sort(a+1,a+n+1);
	int bz=1;
	for(int i=2;i<=n;i++)
	{
		cha[i]=a[i]-a[bz];
		if(cha[i]>=0)bz=i;
	}
	for(int i=2;i<=n;i++)
	{
		if(cha[i]>=0)
		pre[i]=pre[i-1]+cha[i];
		else pre[i]=pre[i-1];
	}
	for(int i=2;i<=n;i++)
	{
		if(cha[i]>=0)
		bl[i]=bl[i-1]+cha[i]*(i-1);
		else bl[i]=bl[i-1]+abs(cha[i]);
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int l=i,r=n;
		while(l<=r)
		{
			int mid=(l+r)/2;
			if(ak(i,mid)<=m)l=mid+1;
			else r=mid-1;
		}
		ans=max(ans,r-i+1);
	}
	cout<<ans<<endl;//1 4 8 7 -4 -1 7
	return 0;
}
