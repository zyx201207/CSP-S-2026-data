#include<bits/stdc++.h>
#define AKIOI ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int N=2e5+10,INF=INT_MAX;
int n,m,mod=1,a[N],x,sum[35],ans;
bool f[N][35],flag[N];
signed main()
{
  AKIOI;
  freopen("and.in","r",stdin);
  freopen("and.out","w",stdout);
  cin>>n>>m;
  for(int i=1;i<=30;i++) mod*=2;
  for(int i=1;i<=n;i++)
  {
  	cin>>a[i];
  	flag[i]=true;
  	x=a[i];
  	int k=31;
  	for(int j=mod;j>=1;j/=2)
  	{
  	  if(x>=j)
  	  {
  	  	f[i][k]=true;
  	  	x-=j;
	  }
	  else
	  {
	  	f[i][k]=false;
	  }
	  k--;
	}
  }
  int k=mod*2;
  for(int i=31;i>=1;i--)
  {
  	k/=2;
  	for(int j=1;j<=n;j++)
  	{
  	  if(!flag[j]) continue;
  	  if(f[j][i]) sum[i]++;
	}
  	if(sum[i]<m) continue;
  	ans+=k;
  	for(int j=1;j<=n;j++)
  	{
  	  if(!f[j][i])
  	  {
  	  	flag[j]=false;
	  }
	}
  }
  cout<<ans; 
  return 0;
}
