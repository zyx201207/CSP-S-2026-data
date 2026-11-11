#include<bits/stdc++.h>

using namespace std;
#define int long long 
#define ull unsigned long long 

const int N=1e6+15;

int n,m;
int a[N];

void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	priority_queue<int> q;
	for(int i=1;i<=n;i++) q.push(a[i]);
	int cnt=0;
	int ans=0;
	for(int i=n;i>=1;i--)
	{
		int limit=a[i];
		if(i!=n) m=m+cnt*(a[i+1]-a[i]);
		while(!q.empty()&&q.top()+m>=limit)
		{
			cnt++;
			m=m-(limit-q.top());
			q.pop();
		}
		ans=max(ans,cnt);
		cnt--;
	}
	cout<<ans<<endl;
}

signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--)
		solve();
	return 0;
}