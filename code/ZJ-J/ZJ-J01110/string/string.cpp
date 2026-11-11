#include<bits/stdc++.h>
#define ll long long
#define AC ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
const int N=2e5+10;
ll a[N],n,ans=0;
int b[N];
int main()
{
  freopen("string.in","r",stdin);
  freopen("string.out","w",stdout);
  AC;
  cin>>n;
  for(ll i=1;i<=n;i++)
  {
  	char ch;
  	cin>>a[i]>>ch;
  	b[i]=ch-'a'+1;
  }
  ll l=0,r=n;
  while(l<r)
  {
  	if(b[l]==b[r])
  	{
  	  if(a[l]==a[r])
  	  {
  	  	l++,r--;
	  }
  	  else if(a[l]>a[r])
  	  {
  	  	a[l]-=a[r];
  	  	r--;
	  }
  	  else
  	  {
  	  	a[r]-=a[l];
  	  	l++;
	  }
	}
	else
	{
  	  if(a[l]==a[r])
  	  {
  	  	ans+=a[l];
  	  	l++,r--;
	  }
  	  else if(a[l]>a[r])
  	  {
  	  	ans+=a[r];
  	  	a[l]-=a[r];
  	  	r--;
	  }
  	  else
  	  {
  	  	ans+=a[l];
  	  	a[r]-=a[l];
  	  	l++;
	  }
	}
  }
  cout<<ans;
  return 0;
}
