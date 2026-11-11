#include<bits/stdc++.h>
using namespace std;
long long read()
{
	long long x=0,f=1;
	char c;
	c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
long long c,t,n,d,x[2000020],dis[5050][5050],ans,sum;
vector<long long> g[5050];
bool vis[5050];
void dfs(long long x,long long goal,long long step,long long st)
{
//	cout<<st<<" "<<goal<<" "<<x<<" "<<step<<"\n";
	if(sum>2) return ;
	if(step>dis[st][goal]) return ;
	if(step+dis[x][goal]>dis[st][goal]) return ;
	if(x==goal&&step==dis[st][goal])
	{
		sum++;
		return ;
	} 
	for(long long i=0;i<g[x].size();i++)
	{
		long long to=g[x][i];
		if(to>goal||vis[to]) continue;
		vis[to]=1;
		dfs(to,goal,step+1,st);
		vis[to]=0;
	}
}
void solve1()
{
		for(long long i=1;i<=n;i++)
		{
			g[i].clear();
			for(long long j=i+1;j<=n;j++)
			{
				if(x[j]-x[i]<=d)
				{
					g[i].push_back(j);
				}
				else break;
			}
		}
//		for(long long i=1;i<=n;i++)
//		{
//			for(long long j=0;j<g[i].size();j++)
//			{
//				cout<<i<<"->"<<g[i][j]<<"\n";
//			}
//		}
		ans=0;
		for(long long i=1;i<=n;i++)
		{
			for(long long j=i+1;j<=n;j++)
			{
				dis[i][j]=0;
				long long pos=0;
				sum=0;
				long long lst=x[i];
				while(1)
				{
					dis[i][j]++;
					long long to=lst+d;
					long long l=i,r=j;
					while(l<=r)
					{
						long long mid=(l+r)/2;
						if(x[mid]<=to)
						{
							pos=mid;
							l=mid+1;
						}
						else
						{
							r=mid-1;
						}
					}
					
					lst=x[pos];
				//	cout<<i<<" "<<j<<" "<<pos<<" "<<l<<" "<<r<<endl;
					if(pos>=j) break;
					if(x[pos+1]-x[pos]>d) 
					{
						dis[i][j]=LLONG_MAX;
						break;
					} 
				}
			//	cout<<i<<"->"<<j<<" "<<dis[i][j]<<"\n";
				if(dis[i][j]==LLONG_MAX)
				{
					continue;
				}
				vis[i]=1;
				dfs(i,j,0,i);
				vis[i]=0;
				if(sum==2) 
				{
					ans++;
			//		cout<<i<<"->"<<j<<endl;
				}
			}
		}
		cout<<ans<<endl;
}
void solve2()
{
	int step=0;
	step=d/(x[2]-x[1]);
	ans=n-2*step+1;
	if(ans<0) ans=0;
	if(step==1||step==0) ans=0;
	cout<<ans<<endl;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read();t=read();
	while(t--)
	{
		n=read();d=read();
		for(long long i=1;i<=n;i++)
		{
			x[i]=read();
		}
		if(c>=1&&c<=2)
		{
			solve1();
			continue;
		}
		if(c>=11&&c<=12)
		{
			solve2();
			continue;
		}
	}
}//10pts
//1 2
//4 2
//1 2 3 4
//5 2
//1 2 3 4 5

//0 2
//5 3
//-2 -1 0 1 2
//6 2
//-4 -3 -2 -1 3 6

//11 2
//5 3
//-2 0 2 4 6
//6 8
//-4 0 4 8 12 16