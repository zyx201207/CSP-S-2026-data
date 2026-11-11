#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
ll m,sum,maxn=INT_MIN,minn=INT_MAX;
priority_queue<ll> q;
stack<ll> s;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	ll a[n+10]={},b[n+10]={};
	for(int i=0;i<n;++i)
	{
		cin>>a[i];
		q.push(a[i]);
	}
	for(int i=0;i<n;++i)
	{
		s.push(q.top());
		q.pop();
	}
	while(m>0)
	{
		int zc1,zc2,ls=1;
		sum+=1;
		zc1=s.top();
		s.pop();
		zc2=s.top();
		m-=(zc2-zc1)*ls;
		++ls;
	}
	cout<<sum;
	return 0;
}
