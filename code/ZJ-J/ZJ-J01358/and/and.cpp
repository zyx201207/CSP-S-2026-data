#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N=2e5+10;
int n,m,a[N],ans=-2147483647,cnt,maxx,x,y,z;
bool vis[21],flagb=1;
map<int,bool> u;
void dfs(int x,int now)
{
	if(x==m)
	{
		ans=max(ans,now);
		return;
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			if(!vis[i])
			{
				vis[i]=1;
				dfs(x+1,( now & a[i] ));
				vis[i]=0;
			}
		}
	}
}
int main()
{
//	 务必删除注释！！！
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];maxx=max(a[i],maxx);
		if(a[i]==1)  x++;
		if(a[i]==2)  y++;
		if(a[i]==3)  z++;
		if(a[i]!=i-1)  flagb=0;
	}
	for(int i=1;i<=30;i++) u[pow(2,i)]=1;
	if(n<=20)
	{
		for(int i=1;i<=n;i++)
		{
			vis[i]=1;
			dfs(1,a[i]);
			vis[i]=0;
		}
		cout<<ans;
	}
	else
	{
		sort(a+1,a+1+n);
		if(m==1)
		{
			cout<<a[n];
			return 0;
		}
		if(m==2&&n<=5000)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j!=i;j++)
				{
					ans=max(ans, (a[i] & a[j]));
				}
			}
			cout<<ans;
			return 0;
		}
		if(m==n)
		{
			ans=a[1];
			for(int i=2;i<=n;i++)  ans&=a[i];
			cout<<ans;
			return 0;
		}
		if(flagb)
		{
			cout<<n-m;
			return 0;
		}
		if(maxx<4)
		{
			if(m<=z)  cout<<3;
			else if(m<=y+z)  cout<<2;
			else  cout<<1;
			return 0;
		}
		int t=0,f=0;ans=2147483647;
		for(int i=n;i>=n-m+1-t;i--)
		{
			if(!u[a[i]])  
			{
				ans=(ans&a[i]);
			}
			else if(n-m+1-t>1)  t++;
			else
			{
				f=1;
				break;
			}
		}	
		if(f)  cout<<0;
		else  cout<<ans;
	}
	return 0;
}

