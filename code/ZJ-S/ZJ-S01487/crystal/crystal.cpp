#include<bits/stdc++.h>
#define AKIOI ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int N=5e5+10,INF=INT_MAX;
struct V
{
  int sum,l;
}s[N];
int n,m,a[N],tot,ans;
signed main()
{
  AKIOI;
  freopen("crystal.in","r",stdin);
  freopen("crystal.out","w",stdout);
  cin>>n>>m;
  for(int i=1;i<=n;i++)
  {
  	cin>>a[i];
  }
  sort(a+1,a+n+1);
  int now=a[1],nown=1;
  for(int i=2;i<=n;i++)
  {
  	if(a[i]!=now)
  	{
  	  tot++;
  	  s[tot].sum=now;
  	  s[tot].l=nown;
  	  now=a[i];
  	  nown=1;
	}
	else nown++;
  }
  tot++;
  s[tot].sum=now;
  s[tot].l=nown;
  int j=n,nowl=0;
  for(int i=tot;i>=2;i--)
  {
  	while(a[j]==s[i].sum)
	{
	  j--;
	  nowl++;
	}
  	while(j>=1)
  	{
  	  if(s[i].sum-a[j]<=m)
  	  {
  	  	m-=(s[i].sum-a[j]);
  	  	nowl++;
  	    j--;
	  }
	  else
	  {
	  	break;
	  }
	}
  	ans=max(ans,nowl);
  	m+=((nowl-s[i].l)*(s[i].sum-s[i-1].sum));
  	nowl-=s[i].l;
  }
  cout<<ans;
  return 0;
}
