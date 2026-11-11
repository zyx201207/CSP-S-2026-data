#include<bits/stdc++.h>
using namespace std;

#define int long long

int n,m;
int a[600005];
int ji = 0;
struct ysr
{
	int p,w;
	int friend operator < (ysr a,ysr b)
	{
		return a.p > b.p;
	}
};
priority_queue<ysr> q;
vector<int> v;
int ans,cnt = 1;
int o = 0;

signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	sort(a + 1,a + 1 + n);
	if(n == 1)
	{
		cout << 1;
		return 0;
	}
	
	int l = 1,r = 1;
	for(int i = 2;i <= n;i++)
	{
		q.push({i-1 , a[i] - a[i-1]});
		o += (q.size()) * (a[i] - a[i-1]);
		int oo = q.size();
		if(o <= m) ans = max(ans , oo + 1);
		else while(o > m) o -= a[i] - a[q.top().p] , q.pop();
	}
	//cout << n << " " << m;
	cout << ans;
	return 0;
}
