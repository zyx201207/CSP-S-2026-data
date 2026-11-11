#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int a[200005];
struct node 
{
	int id;
	string s;
	
}ejz[200005];
void zhuanh(int n,int i)
{
	int t=n;
	int cur=0;
	while(t)
	{
		ejz[i].s[cur++]=(t%2)+'0';
		t/=2;
	}
}
void chang(int n)
{
	for(int i=1;i<=n;i++)
	{
		zhuanh(a[i],i);
	}
}
bool cmp(node x,node y)
{
	for(int i=30;i>=0;i--)
	{
		if(x.s[i]!=y.s[i])return x.s[i]>y.s[i];
	}
}
void solveb(int m,int n)
{
	long long ans=n-1;
	for(int i=2;i<=m;i++)
	{
		ans&=(n-i);
	}
	cout<<ans;
 } 
int main()
{ 
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	bool checkb=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=(i-1))checkb=0;
		ejz[i].s="0000000000000000000000000000000";
		ejz[i].id=i;
	}
	chang(n);
	if(n<=2000||m==n-1)
	{
		sort(ejz+1,ejz+n+1,cmp);
		long long ans=-1e18;
		for(int i=1;i<=n-m+1;i++)
		{
			long long t;
			for(int j=i;j<=i+m-1;j++)
			{
				int xb=ejz[j].id;
				if(j==i)t=a[xb];
				else t&=a[xb];
			}
			ans=max(ans,t);
		}
		cout<<ans;
		return 0;
	}
	if(n<=200000)
	{
		if(checkb)
		{
			for(int i=1;i<=19;i++)
			{
				if(n==pow(2,i))
				{
					solveb(m,n);
					return 0;
				}
			}
		}
		sort(ejz+1,ejz+n+1,cmp);
		long long ans;
		for(int i=1;i<=m;i++)
		{
			int xb=ejz[i].id;
			if(i==1)ans=a[xb];
			else ans&=a[xb];
		
		}
		cout<<ans;
		return 0;
		
	}
	return 0;
}
