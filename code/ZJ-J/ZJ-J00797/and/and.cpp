#include<bits/stdc++.h>//01dfs 25pts
#define int long long
using namespace std;
/*
思路：拿特殊点 01dfs  
*/
const int dx[]={0,1,-1,0,0},dy[]={0,0,0,1,-1},N=2e5+5;
int n,m,vis[N],ans=-1,a[N],minn=1e18,maxx=-1e18;
map<int,int>mp;
void dfs(int x,int sum,int c)//x是
{
	if(c==m)
	{
		ans=max(ans,sum);
//		cout<<ans<<" ";
		return;
	}
	if(x>=n+1)
	{
		return;
	}
	vis[x]=1;
	dfs(x+1,sum&a[x],c+1);
	vis[x]=0;
	dfs(x+1,sum,c);
	return;
}
bool cmp(int x,int y)
{
	return x>y;
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	int f=1;//p230=pow(2,30);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		int b=a[i];
		maxx=max(maxx,a[i]);
		minn=min(minn,a[i]);
		if(f==0)continue;
		int tt=1;
		if(a[i]==1)
		{
			continue;
		}
		while(b<=1)
		{
			tt=b&1;
			if(tt==0)
			{
				f=0;
				break;
			}
		}
		
	}
	if(n==m)//5
	{
		int s=a[1];
		for(int i=2;i<=n;i++)
		{
			s&=a[i];
		}
		cout<<s;
		return 0;
	}
	if(m==1)//5
	{
		int mx=-1e18;
		for(int i=1;i<=n;i++)
		{
			mx=max(mx,a[i]);
		}
		cout<<mx;
		return 0;
	}
	if(m==2)
	{
		int mx=-1e18;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				mx=max(mx,a[i]&a[j]);
			}
		}
		cout<<mx;
		return 0;
	}
	if(m==n-1)//0
	{
		int t,mx=-1e18;
		for(int i=1;i<=n;i++)//遍历不取的数字
		{
			if(i!=1)
			{
				t=a[1];
			}
			if(i==1)
			{
				t=a[2];
			}
			for(int j=2;j<=n;j++)
			{
				if(i==j)
				{
					continue;
				}
				t&=a[i];
			}
			mx=max(mx,t);
		}
		cout<<mx;
		return 0;
	}
	if(f==1)
	{
		sort(a+1,a+1+n,cmp);
		cout<<a[m];
		return 0;
	}
	if(maxx<4)//10pts
	{
		for(int i=1;i<=n;i++)
		{
			mp[a[i]]++;
		}
		if(mp[3]>=m)
		{
			cout<<3;
		}
		else if(mp[3]+mp[2]>=m)
		{
			cout<<2;
		}
		else if(mp[3]+mp[1]>=m)
		{
			cout<<1;
		}
		else
		{
			cout<<0;
		}
		return 0;
	}
	dfs(1,pow(2,30)-1,0);
	cout<<ans;
	return 0;
}
/*
写暴力 写特殊点 B想不出来 出来了应该就有一等了 
*/
