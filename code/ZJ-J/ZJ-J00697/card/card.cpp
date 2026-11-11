#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500001],q[501],t[5001],jl[5001];
stack<int> sta;
bool flag=1;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]<a[i-1]) flag=0;
	}
	if(flag)
	{
		n=unique(a+1,a+n+1)-a-1;
		for(int i=1;i<=n;i++)
		{
			jl[a[i]]=i;
		}
		for(int i=1;i<=m;i++) cout<<jl[i]<<" "; 
		return 0;
	}
	if(n>5000) n=unique(a+1,a+n+1)-a-1;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(t[a[j]]==0) t[a[j]]++,sta.push(a[j]);
			else while(sta.top()!=a[j]) t[sta.top()]--,sta.pop();
		}
		while(!sta.empty())
		{
			jl[sta.top()]++;
			sta.pop();
		}
		memset(t,0,sizeof(t));
	}
	for(int i=1;i<=m;i++) cout<<jl[i]<<" ";
	return 0;
}