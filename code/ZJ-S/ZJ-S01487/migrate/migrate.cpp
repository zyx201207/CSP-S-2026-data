#include<bits/stdc++.h>
#define AKIOI ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int N=1e5+10,INF=INT_MAX;
int c,t,n,d,a[N],best[N],sum,minn,ans;
void dfs(int s,int e,int now,int l)
{
  if(now==e)
  {
  	if(l==minn) sum++;
  	return ;
  }
  if(now<=best[l-1]) return ;
  for(int i=now+1;i<=n;i++)
  {
  	if(a[i]-a[now]<=d) dfs(s,e,i,l+1);
  }
  return ;
}
signed main()
{
  AKIOI;
  freopen("migrate.in","r",stdin);
  freopen("migrate.out","w",stdout);
  cin>>c>>t;
  while(t--)
  {
  	cin>>n>>d;
  	for(int i=1;i<=n;i++) cin>>a[i];
  	if(n>300)
  	{
	  cout<<0<<endl;
  	  continue;
	}
  	ans=0;
  	for(int i=1;i<n;i++)
  	{
  	  for(int j=i+1;j<=n;j++)
  	  {
  	  	int st=i;
  	  	bool flag=true;
  	  	minn=0;
  	  	while(a[j]-a[st]>d)
  	  	{
  	  	  int nxt=st+1;
  	  	  if(a[nxt]-a[st]>d)
  	  	  {
  	  	  	flag=false;
  	  	  	break;
		  }
  	      while(nxt<=n && a[nxt]-a[st]<=d) nxt++;
  	  	  nxt--;
  	  	  minn++;
  	  	  best[minn]=nxt;
  	  	  st=nxt;
		}
		if(!flag) continue;
  	  	minn++;
  	  	sum=0;
  	  	dfs(i,j,i,0);
  	  	if(sum==2) ans++;
	  }
	}
	cout<<ans<<endl;
  }
  return 0;
}
