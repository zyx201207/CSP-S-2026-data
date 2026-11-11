#include<iostream>
#include <queue>
#include <vector>
#include <cstdio>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 500086;
priority_queue<ll,vector<ll>,greater<ll> > q;
ll n;
ull m;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%ulld",&n,&m);
	ll x;
	for(int i = 1; i <=n;i++)
	{
		scanf("%lld",&x);
		q.push(x);
	}
	ll cnt=1;
	ll h = q.top();
	q.pop();
	while(m)
	{
		if((ll)m-cnt*(q.top()-h)<0)
		{
			if((ll)m>0)break;
		}
		m-=cnt*(q.top()-h);
		cnt++;
		h = q.top();
		q.pop();
		if(q.empty())break;
	}
	while(q.top()==h)
	{
		q.pop();
		cnt++;
	}
	printf("%lld",cnt);
	return 0;
}
