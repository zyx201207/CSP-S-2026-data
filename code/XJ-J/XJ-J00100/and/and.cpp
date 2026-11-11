#include <bits/stdc++.h>
using namespace std;
long long n, m, a[200005];
priority_queue<long long> pq;
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		pq.push(a[i]);
	}
	long long ans=pq.top();
	for(int i=1;i<=m;i++)
	{
		ans&=pq.top();
		pq.pop();
	}
	cout<<ans<<endl;
	return 0;
}
