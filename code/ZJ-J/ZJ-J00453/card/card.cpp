#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans[500005];
bool vis[500005];
void sol1()
{
	for (long long i=1; i<=n; i++)
	{
		cin>>a[i];
		ans[a[i]]++;
	}
	for (long long i=1; i<=m; i++)
		ans[i]+=ans[i-1];
}
void sol2()
{
	for (long long i=1; i<=n; i++)
	{
		cin>>a[i];
		ans[a[i]]++;
	}
	ans[a[n]]=n;
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	if (n>5000) sol1();
	else if (m<=2) sol2();
	else
	{
		stack<long long> s;
	    for (long long i=1; i<=n; i++) cin>>a[i];
	    for (long long i=1; i<=n; i++)
    	{
	    	for (long long j=1; j<=m; j++) vis[j]=0;
	    	for (long long j=i; j<=n; j++)
	    		if (!vis[a[j]]) vis[a[j]]=1,s.push(a[j]);	
	    		else while(s.top()!=a[j]) vis[s.top()]=0,s.pop();
	    	while (!s.empty()) ans[s.top()]++,s.pop();
	    }
    }
	for (long long i=1; i<=m; i++) cout<<ans[i]<<" ";
	return 0;
}