#include<bits/stdc++.h>
using namespace std;
int n,k,u[1000010],v[1000010],d[1000010],pa[1000010],dm[1000010],ans,l[1000010],r[1000010],idqwq[1000010];
vector <int> b[1000010];
bool vis[1000010];
void dfs(int id)
{vis[id]=1;
 for(int i=0;i<b[id].size();i++)
 {if(!vis[b[id][i]]) {pa[b[id][i]]=id;d[b[id][i]]=d[id]+1;dfs(b[id][i]);}
 }
}
void dfs2(int id)
{vis[id]=1;dm[id]=0;
 for(int i=0;i<b[id].size();i++)
 {if(vis[b[id][i]]) continue;
  dfs2(b[id][i]);
  dm[id]=max(dm[id],dm[b[id][i]]+1);
 }
}
int solve(int rt)
{d[rt]=0;dfs(rt);int id1=0,id2=0;
 for(int i=1;i<=n;i++) if(vis[i]&&d[i]>=d[id1]) id1=i;
 for(int i=1;i<=n;i++) vis[i]=0;
 d[id1]=0;dfs(id1);
 for(int i=1;i<=n;i++) if(vis[i]&&d[i]>=d[id2]) id2=i;
 //找直径中点
 int dd=d[id2]/2,id=id2;
 while(d[id]!=dd)
 id=pa[id];
 for(int i=1;i<=n;i++) vis[i]=0;
 dfs2(id);
 return id;
}
void solve2()
{dfs(1);int id1=0,id2=0;
 for(int i=1;i<=n;i++) if(vis[i]&&d[i]>=d[id1]) id1=i;
 for(int i=1;i<=n;i++) vis[i]=0;
 d[id1]=0;dfs(id1);
 for(int i=1;i<=n;i++) if(vis[i]&&d[i]>=d[id2]) id2=i;
 //得到直径两端
 for(int i=1;i<=n;i++) vis[i]=0;
 int id=id2,tt=0;vis[id]=1;idqwq[++tt]=id;
 while(id!=id1) {id=pa[id];vis[id]=1;idqwq[++tt]=id;}
 for(int i=1;i<=tt;i++) dfs2(id);
 int _max=-1;
 for(int i=1;i<=tt;i++)
 {_max++;l[i]=max(l[i-1],_max+dm[idqwq[i]]);
  _max=max(_max,dm[i]);
 }
 _max=-1;r[tt+1]=0;
 for(int i=tt;i>=1;i--)
 {_max++;r[i]=max(r[i+1],_max+dm[idqwq[i]]);
  _max=max(_max,dm[i]);
 }
 int ans=1e9;
 for(int i=0;i<=tt;i++)
 ans=min(ans,(max(l[i],r[i+1])+1)/2);
 cout<<ans<<'\n';
}
int main()
{freopen("hub.in","r",stdin);
 freopen("hub.out","w",stdout);
 int cc,t;cin>>cc>>t;
 while(t--)
 {cin>>n>>k;
  for(int i=1;i<n;i++)
  cin>>u[i]>>v[i];
  if(n==k) {cout<<"0\n";continue;}
  //好像会 n^2 了
  //暴力枚举两个影响范围分界线，先取直径中点为根，然后 priority_queue
  //特判只有一个连通块
  for(int i=1;i<=n;i++) vis[i]=0,b[i].clear();
  for(int i=1;i<n;i++) b[u[i]].emplace_back(v[i]),b[v[i]].emplace_back(u[i]);
  if(cc==11||cc==12) {solve2();continue;}
  int id=solve(1);
  priority_queue <pair<int,int>> q;
  //id 为根（必取）贪心
  q.push({dm[id],id});
  for(int i=1;i<=n;i++) vis[i]=0;
  int cntt=0;
  while(cntt<k)
  {int idd=q.top().second;q.pop();vis[idd]=1;cntt++;
   for(int i=0;i<b[idd].size();i++)
   if(!vis[b[idd][i]]) q.push({dm[b[idd][i]],b[idd][i]});
  }
  ans=q.top().first+1;//cout<<ans<<'\n';
  for(int _=1;_<n;_++) //枚举分界边
  {if(cc==13||cc==14) _=(n/2+1)/2;
   for(int i=1;i<=n;i++) vis[i]=0,b[i].clear();
   for(int i=1;i<n;i++) if(i!=_) b[u[i]].emplace_back(v[i]),b[v[i]].emplace_back(u[i]);
   int id1=solve(u[_]);
   for(int i=1;i<=n;i++) vis[i]=0;
   int id2=solve(v[_]);
   while(!q.empty()) q.pop();
   q.push({dm[id1],id1});q.push({dm[id2],id2});
   int cntt=0;
   for(int i=1;i<=n;i++) vis[i]=0;
   int idd=q.top().second;q.pop();vis[idd]=1;cntt++;
   int idd2=q.top().second;q.pop();vis[idd2]=1;cntt++;
   for(int i=0;i<b[idd].size();i++)
   if(!vis[b[idd][i]]) q.push({dm[b[idd][i]],b[idd][i]});
   for(int i=0;i<b[idd2].size();i++)
   if(!vis[b[idd2][i]]) q.push({dm[b[idd2][i]],b[idd2][i]});
   while(cntt<k)
   {int idd=q.top().second;q.pop();vis[idd]=1;cntt++;
    for(int i=0;i<b[idd].size();i++)
    if(!vis[b[idd][i]]) q.push({dm[b[idd][i]],b[idd][i]});
   }
   ans=min(ans,q.top().first+1);
   if(cc==13||cc==14) break;
  }
  cout<<ans<<'\n';
 }
}
