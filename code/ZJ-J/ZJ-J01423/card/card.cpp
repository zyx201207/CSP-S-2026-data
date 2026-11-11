#include<bits/stdc++.h>
#define AKIOI ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int N=5e5+10,INF=INT_MAX;
struct V
{
  int l,r;
};
int n,m,a[N],nxt[N],flag[N],ok,ans[N],sum[N];
bool flag1=true;
vector<int> f[N];
signed main()
{
  AKIOI;
  freopen("card.in","r",stdin);
  freopen("card.out","w",stdout);
  cin>>n>>m;
  for(int i=1;i<=n;i++)
  {
  	cin>>a[i];
  	f[a[i]].push_back(i);
  	nxt[i]=-1;
  	sum[a[i]]++;
  	if(i>=2 && a[i]<a[i-1]) flag1=false;
  }
  if(n>5000 && flag1)
  {
    for(int i=2;i<=m;i++) sum[i]+=sum[i-1];
    for(int i=1;i<=m;i++) cout<<sum[i]<<" ";
    return 0;
  }
  for(int i=1;i<=m;i++)
  {
  	for(int j=0;j<f[i].size()-1;j++)
  	{
  	  nxt[f[i][j]]=f[i][f[i].size()-1];
	}
  }
  for(int i=1;i<=n;i++)
  {
  	ok=m;
  	for(int j=i;j<=n;j++)
  	{
  	  if(flag[a[j]]!=i) ok--;
  	  flag[a[j]]=i;
  	  if(ok==0) break;
  	  if(nxt[j]!=-1) j=nxt[j];
	}
	for(int j=1;j<=m;j++)
	{
	  if(flag[j]==i) ans[j]++;
	}
  }
  for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
  return 0;
}
