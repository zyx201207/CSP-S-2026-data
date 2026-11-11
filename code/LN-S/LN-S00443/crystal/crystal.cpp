#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
priority_queue<int>q;
int a[N],v[N],idx,s[N];
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;
    idx=n;
    for(int i=1;i<=n;i++)
    {
		int x;
		cin>>x;
		q.push(x);
	}
	while(q.size())
	{
		a[idx--]=q.top();
		q.pop();
	}
	int sum=0;
	for(int i=2;i<=n;i++)
	{
		sum+=(a[i]-a[i-1])*(i-1);
		if(sum>m)
		{
			cout<<i-1;
			return 0;
		}
	}
	cout<<n;
    return 0;
}
