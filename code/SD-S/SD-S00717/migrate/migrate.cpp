#include<bits/stdc++.h>
using namespace std;
struct Node{
	int to,step;
};
const int N=2e6+10;
int a[N],dis[N],sum,cnt,n,D,ans;
void bfs(int x,int y)
{
	queue<Node> q;
	q.push({x,0});
	cnt=0;
	sum=-1;
	dis[x]=0;
	while(!q.empty())
	{
		Node u=q.front();
		q.pop();
		if(u.step>sum&&sum!=-1) break;
		if(u.to==y&&sum==-1) sum=u.to;
		if(u.to==y&&u.to==sum) 
		{
			sum=u.to;
			cnt++;	
		}
		if(u.to>y) continue;
		 
		for(int i=u.to+1;i<=y;i++)
		{
			if(a[i]-a[u.to]>D) break;
			q.push({i,u.step+1});
		}
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	int c,T;
	cin>>c>>T;
	while(T--)
	{
		scanf("%lld%lld",&n,&D);
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<i;j++)
			{
				bfs(j,i);
				if(cnt==2) ans++;
			}
		}
		cout<<ans<<'\n';
	}	
	
	return 0;
}
