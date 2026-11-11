#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;
ll a[500100];
ll jl[500100];
ll b[500100];
ll sl[500100];
ll last[500100];
stack<ll> q;
void calc()
{
	stack<ll> st=q;
	while(!st.empty())
	{
		b[st.top()]++;
		st.pop();
	}
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(ll i=1;i<=m;i++)
	{
		last[i]=n;
	}
	for(ll i=n;i>=1;i--)
	{
		sl[a[i]]++;
		if(sl[a[i]]==1)
		{
			q.push(a[i]);
			b[a[i]]+=last[a[i]]-i;
		}
		else
		{
			sl[a[i]]--;
			while(!q.empty())
			{
				if(q.top()==a[i]) break;
				sl[q.top()]--;
				if(!sl[q.top()]) last[q.top()]=i;
				q.pop();
			}
		}
	}
	while(!q.empty())
	{
		last[q.top()]=0;
		q.pop();
	}
	for(int i=1;i<=m;i++)
	{
		cout<<n-b[i]-last[i]<<' '<<last[i]<<' ';
	}
	cout<<"\n";
	return 0;
}

