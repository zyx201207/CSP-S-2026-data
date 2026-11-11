#include<bits/stdc++.h>
using namespace std;
int n,m,mx,a[200005],b[200005];
bool c[200005];
void dfs(int k)
{
  if(k==m)
  {
    int ans=b[1];
    for(int i=2;i<=m;i++)
      ans&=b[i];
    mx=max(mx,ans);
    return;
  }
  for(int i=1;i<=n;i++)
  {
  	if(!c[i])
  	{
  	  c[i]=1;
  	  b[k]=a[i];
  	  dfs(k++);
  	  c[i]=0;
  	  b[k]=0;
    }
  }
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  freopen("and.in","r",stdin);
  freopen("and.out","w",stdout);
  cin>>n>>m;
  for(int i=1;i<=n;i++)
    cin>>a[i];
  if(m==1)
  {
  	for(int i=1;i<=n;i++)
  	  mx=max(mx,a[i]);
  }
  else if(n==m)
  {
  	mx=a[1];
  	for(int i=2;i<=n;i++)
  	  mx&=a[i];
  }
  else if(m==n-1)
  {
  	for(int i=1,z=1;i<=n;i++,z++)
  	{
  	  int ans;
  	  if(z==1)ans=a[2];
  	  else ans=a[1];
  	  for(int j=1;j<=n;j++)
  	  {
  	    if(j==z)continue;
  	    ans&=a[j];
	  }
	  mx=max(mx,ans);
    }
  }
  else dfs(1);
  cout<<mx;
  return 0;
}
