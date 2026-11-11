#include<bits/stdc++.h>
#define ll long long
#define AC ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
const int N=5e5+10;
ll n,m,a[N],sum,ans;
priority_queue<ll> q;
int main()
{
  freopen("crystal.in","r",stdin);
  freopen("crystal.out","w",stdout);
  AC;
  cin>>n>>m;
  for(ll i=1;i<=n;i++)
  {
  	cin>>a[i];
  }
  sort(a+1,a+n+1);
  for(ll i=1;i<=n;i++)
  {
  	m-=(a[i]-a[i-1])*sum;
  	q.push(-a[i]);
  	sum++;
  	while(m<0)
  	{
  	  sum--;
  	  m+=(a[i]+q.top());
  	  q.pop();
	}
	ans=max(ans,sum);
  }
  cout<<ans;
  return 0;
}
