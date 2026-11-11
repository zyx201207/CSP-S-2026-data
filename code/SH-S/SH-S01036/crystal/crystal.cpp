#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> pre;
vector<ll> a;
int n;
ll m, x;
int find(int st, int lst, int no)
{
	if(a[no]*(no-st+1)-pre[no]+pre[st-1] < m) return (no-st+1);
	int mid = max((st+lst)/2, 0);
	if(a[no]*(no-mid+1)-pre[no]+pre[mid-1] > m){
		return find(mid+1, lst, no);
	}if(a[no]*(no-mid+1)-pre[no]+pre[mid-1] == m){
		return (no-mid+1);
	}else{
		return find(st, mid-1, no);
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int ans = 0;
	cin >> n >> m;
	for(int i = 0;i < n;i++)
	{
		cin >> x;
		a.push_back(x);
	}
	sort(a.begin(), a.end());
	pre.push_back(a[0]);
	for(int i = 1;i < n;i++)
	{
		pre.push_back(a[i]);
		pre[i]+=pre[i-1];
	}
	for(int i = 0;i < n;i++)
		ans = max(ans, find(0, i, i));
	cout << ans;
	return 0;
}
