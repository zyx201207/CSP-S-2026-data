#include<bits/stdc++.h>

#define int long long 
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
const int N = 5e5 + 10;
int n,A[N],m;list<int> pq;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>A[i];
	sort(A+1,A+1+n);
	int ans = 1;
	pq.push_back(A[1]);
	for(int i=2;i<=n;i++)
	{
		int dt = A[i] - A[i-1];
		m -= pq.size() * dt;pq.push_back(A[i]);
		while(m < 0)
		{
			m += A[i] - pq.front();
			pq.pop_front();
		}
		ans = max((int)pq.size(),ans);
	}
	cout<<ans;
	return 0;
}