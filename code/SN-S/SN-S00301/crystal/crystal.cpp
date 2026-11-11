//并不困难，依旧是小贪心
//CSP是已经考成八股了吗，怎么每次T1都是贪心啊
#include<bits/stdc++.h>

using namespace std;

#define N 500005
#define int long long

int n, m, len, a[N], need[N], ans;
unordered_map<int, int> ID;
struct node{int val, num;}b[N];
bool cmp(node x, node y){return x.val < y.val;}

signed main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if(!ID[a[i]])ID[a[i]] = ++len, b[len] = {a[i], 0};
		b[ID[a[i]]].num++;
	}
	sort(b + 1, b + len + 1, cmp);
	int l = 1, r, sum = 0, cnt = 0;
	for(int i = 1; i <= len; i++)need[i] = b[i].num;
	for(r = 1; r <= len; r++)
	{
		sum += cnt * (b[r].val - b[r - 1].val), cnt += b[r].num;
		while(l < r && sum - (b[r].val - b[l].val) * need[l] >= m)
			sum -= (b[r].val - b[l].val) * need[l], cnt -= need[l], l++;
		if(sum > m)
		{
			int delta = (sum - m + b[r].val - b[l].val - 1) / (b[r].val - b[l].val);
			cnt -= delta, need[l] -= delta, sum -= delta * (b[r].val - b[l].val);
		}
		ans = max(ans, cnt);
	}
	cout << ans;
	return 0;
} 
