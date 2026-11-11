#include<iostream>
#include<cmath>
#include<cstring>
#include<queue>
#include<stack>
#include<algorithm>
#include<vector>

using namespace std;

const int N=2e6+6;
const int M=5005;

int c;
int t;

int n;
long long d;

long long a[N];
vector<int> vec[N];

int vis[N];
int f[N];

struct que
{
	int u;
	int s;
	int sum;
};

void bfs(int start)
{
	queue<que> q;
	queue<que> qq;
	q.push({start,0,1});
	
	while(!q.empty())
	{
		int u=q.front().u;
		int s=q.front().s;
		int sum=q.front().sum;
		q.pop();
		
		for(auto v:vec[u])
		{
			if(vis[v]!=0&&vis[v]<s+1) continue;
			
			if(!vis[v])
			{
				qq.push({v,s+1,0});
			}
			vis[v]=s+1;
			f[v]+=sum;
		}
		
		if(q.empty())
		{
			while(!qq.empty())
			{
				q.push({qq.front().u,qq.front().s,f[qq.front().u]});
				qq.pop();
			}
		}
	}
}

int far[N];
long long cha;
bool pd;

void solve()
{
	cin>>n;
	cin>>d;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		
		vec[i].clear();
	}
	
	if(n<=5000)
	{
		for(int i=1;i<=n;i++)
		{
			int j=i+1;
			while(j<=n&&a[j]-a[i]<=d)
			{
				vec[i].push_back(j);
				j++;
			}
		}
		
		long long ans=0;
		
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++) vis[j]=0,f[j]=0;
			bfs(i);
			for(int j=1;j<=n;j++)
			{
	//			cout<<f[j]<<" ";
				
				if(f[j]==2) ans++;
			} 
			
	//		cout<<"\n";
		}
		
		cout<<ans<<"\n";
		
		return ;
	}
	
	
	pd=1;
	cha=a[2]-a[1];
	
	for(int i=3;i<=n;i++)
	{
		if(a[i]-a[i-1]!=cha)
		{
			pd=0;
			break;
		} 
	}
	
	if(pd)
	{
		for(int i=1;i<=n;i++)
		{
			int l=i,r=n;
			while(l<r)
			{
				int mid=(l+r+1)>>1;
				if(a[mid]-a[i]<=d) l=mid;
				else r=mid-1;
			}
			
			far[i]=l;
	//		cout<<l<<" ";
		}
		
		long long ans=0;
		
		for(int i=1;i<=n;i++)
		{
			int farr=far[i];
			if(farr==i||farr-1==i) continue;
			else if(farr-i==2)
			{
				ans+=far[farr-1]-farr;
			}
			else
			{
				ans+=far[farr-1]-far[farr-2]; 
			}
		}
		
		cout<<ans<<"\n";
		
	}
	
	return ;
}

int main() {
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin>>c;
	cin>>t;
	while(t--) solve();
	
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

*/
