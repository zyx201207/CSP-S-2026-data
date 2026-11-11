#include<bits/stdc++.h>
#define ll long long
#define AC ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
ll n,m,l=0,ans,s=1,as,bs;
priority_queue<ll> qa,qb;
int main()
{
  freopen("and.in","r",stdin);
  freopen("and.out","w",stdout);
  AC;
  cin>>n>>m;
  for(ll i=1;i<=n;i++)
  {
  	ll a;
  	cin>>a;
  	qa.push(a);
  }
  as=n;
  ll qs=qa.top();
  while(qs!=0)
  {
  	qs>>=1;
  	l++;
  	s<<=1;
  }
  while(l>0)
  {
  	l--;
    s>>=1;
    while(!qa.empty() && ((qa.top()%(s<<1))>=s)!=0)
    {
      as--;
      bs++;
      qb.push(qa.top()%s);
      qa.pop();
	}
	if(bs>=m)
	{
	  ans+=s;
	  while(!qa.empty()) qa.pop();
	  as=bs;
	  bs=0;
	  while(!qb.empty())
	  {
	  	qa.push(qb.top());
	  	qb.pop();
	  }
	}
	else
	{
	  as+=bs;
	  bs=0;
	  while(!qb.empty())
	  {
	  	qa.push(qb.top());
	  	qb.pop();
	  }
	}
  }
  cout<<ans;
  return 0;
}
