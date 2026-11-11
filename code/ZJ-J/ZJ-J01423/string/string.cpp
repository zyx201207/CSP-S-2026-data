#include<bits/stdc++.h>
#define AKIOI ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int N=2e5+10,INF=INT_MAX;
int n,a[N],la,ra,ans;
char c[N],lc,rc;
signed main()
{
  AKIOI;
  freopen("string.in","r",stdin);
  freopen("string.out","w",stdout);
  cin>>n;
  for(int i=1;i<=n;i++)
  {
  	cin>>a[i]>>c[i]; 
  }
  int i=1,j=n;
  la=a[1];
  ra=a[n];
  lc=c[1];
  rc=c[n];
  while(i<j)
  {
  	if(j==i+1)
  	{
  	  if(lc!=rc) ans+=min(la,ra);
  	  break;
	}
  	if(lc!=rc)
  	{
  	  ans+=min(la,ra);
	}
	if(la>ra)
  	{
  	  la-=ra;
  	  j--;
  	  ra=a[j];
  	  rc=c[j];
	}
	else if(la<ra)
	{
	  ra-=la;
  	  i++;
  	  la=a[i];
  	  lc=c[i];
	}
	else if(la==ra)
	{
	  i++;
	  j--;
  	  la=a[i];
  	  lc=c[i];
  	  ra=a[j];
  	  rc=c[j];
	}
  }
  cout<<ans;
  return 0;
}
