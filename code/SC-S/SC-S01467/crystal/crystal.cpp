#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int a[N];
int n,m;
int sum[N];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	int l=1,r=1;
	int cur=1,maxn=1;
	for(int r=1;r<n;r++)
	{
		while(m<cur*(a[r+1]-a[r]))
		{
			m+=a[r]-a[l];
			l+=1,cur-=1;
		}
		m-=cur*(a[r+1]-a[r]);
		cur+=1;
		maxn=max(maxn,cur);
	}
	cout<<maxn;
	return 0;
}