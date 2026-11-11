#include<bits/stdc++.h>
using namespace std;
#define N 2000005
#define ll long long
ll c,t,n,ans,cs[N],cnt[N],d,x[N];
bool vis[N];
vector<int> vec[N];
queue<int> q;
void bfs(int x)
{
  for(int i = 1;i <= n;i++) vis[i] = 0;
   while(q.size()) q.pop();
   q.push(x);
   vis[x] = 1;
   while(q.size())
   {
   	  int t = q.front();
   	  q.pop();
   	  for(int i = 0;i < vec[t].size();i++)
   	  {
   	    int v = vec[t][i];
		if(!vis[v])
		{
		  cs[v] = cs[t] + 1;
   	      cnt[v] += cnt[t];
		  q.push(v);
	      vis[v] = 1;
		}
		else if(cs[t] + 1 == cs[v]) cnt[v] += cnt[t];
	  }
   }
}
int main()
{
  freopen("migrate.in","r",stdin);
  freopen("migrate.out","w",stdout);
  scanf("%lld%lld",&c,&t);
  while(t--)
  {
  	scanf("%lld%lld",&n,&d);
  	ans = 0;
  	for(int i = 1;i <= n;i++) vec[i].clear();
  	for(int i = 1;i <= n;i++) scanf("%lld",&x[i]);
  	for(int i = 1;i <= n;i++)
  	  for(int j = i + 1;j <= n;j++)
  	    if(x[j] - x[i] <= d)
  	    {
  	      vec[i].push_back(j);
  	    }
  	for(int i = 1;i <= n;i++)
	{
      for(int j = 1;j <= n;j++)
	  {
	    cs[j] = 1e19;
        cnt[j] = 0; 
	  }
	  cnt[i] = 1;
	  cs[i] = 0;
	  bfs(i);
	  for(int j = 1;j <= n;j++)
	    if(cnt[j] == 2)
	      ans++;
	}
	  printf("%lld\n",ans);
  }
  return 0;
}
