#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,k,b[100010],x,y,ans,s,MIN;
vector<int> v[100010];
struct node
{
	int x,y;
};
queue<node> q;
int bfs1(int u,int xx)
{
	for(int i=1;i<=n;i++) b[i]=0;
	q.push({u,0});
	while(!q.empty())
	{
		int x=q.front().x,y=q.front().y;
		q.pop();
		if(b[x]) continue;
		b[x]=1;
		if((xx>>x)&1) return y;
		for(int i=0;i<v[x].size();i++)
		if(!b[v[x][i]])q.push({v[x][i],y+1});
	}
}
void bfs2(int u,int xx)
{
	q.push({u,0});
	while(!q.empty())
	{
		int x=q.front().x;
		q.pop();
		if(b[x]) continue;
		b[x]=1;
		for(int i=0;i<v[x].size();i++)
		if(!b[v[u][x]]&&((xx>>v[x][i]-1)&1))
		{
			q.push({v[x][i],0});
		}
	}
}
signed main()
{
	freopen("hub.in","r",stdin);
//	freopen("hub1.in","r",stdin);
	freopen("hub.out","w",stdout);
    scanf("%lld%lld",&c,&t);
    while(t--)
    {
    	scanf("%lld%lld",&n,&k);
    	for(int i=1;i<n;i++)
    	{
    		cin>>x>>y;
    		v[x].push_back(y);
    		v[y].push_back(x);
		}
		MIN=1e18;
    	for(int i=0;i<(1<<n);i++)
    	if(__builtin_popcount(i)==k)
    	{
    		ans=0;
    		for(int j=1;j<=n;j++) b[j]=0;
    		s=0;
    		for(int j=1;j<=n;j++)
    		if((i>>j-1)&1&&!b[j])
    		{
    			s++;
    			bfs2(j,i);
			}
			if(s>2) continue;
			for(int j=1;j<=n;j++)
    		if((i>>j-1)&1)
    		{
    			ans=max(ans,bfs1(j,i));
			}
			MIN=min(MIN,ans);
		}
		printf("%lld\n",MIN);
	}
	return 0;
 } 
 /*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
 */
