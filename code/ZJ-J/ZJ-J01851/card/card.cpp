#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],c[100005],d[100005];
bool b[100005];
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  freopen("card.in","r",stdin);
  freopen("card.out","w",stdout);
  cin>>n>>m;
  for(int i=1;i<=n;i++)
    cin>>a[i];
  for(int i=1;i<=n;i++)
  {
  	memset(b,0,sizeof(b));
  	memset(c,0,sizeof(c));
    for(int j=i;j<=n;j++)
    {
      if(!b[a[j]])
	  {
	    c[a[j]]=j;
	    b[a[j]]=true;
	  }
      else
      {
      	for(int z=c[a[j]];z<=j;z++)
      	  b[a[z]]=false;
      	b[a[j]]=true;
	  }
	}
	for(int j=1;j<=n;j++)
	  if(b[j])d[j]++;
  }
  for(int i=1;i<=m;i++)
    cout<<d[i]<<' ';
  return 0;
}
