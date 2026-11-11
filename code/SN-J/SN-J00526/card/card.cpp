/*
考虑从 n 到 1 枚举 i
对于每个新加入的数字 a[i]
1.若 a[i] 在前面出现过，则 a[i] 第一次出现的轮次 k
第 k 轮所给出的贡献再次生效
2.若 a[i] 未出现过，将第 i 轮记为 a[i] 第一次出现轮次
a[i] 有一次贡献，第 i + 1 轮的贡献再次生效
考虑实现
应该是只用记录每个数字第一出现所给的贡献
对于其他的只需要给第一次出现贡献 + 1 即可
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 5e5 + 5;

int n,m,a[N],lst[N],num[N],cnt[N],sum[N];

bool flag[N];

vector<int> vis;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i<=n;i++) {
		cin >> a[i];
		lst[a[i]] = i;
	}
	lst[0] = n + 1;
	for(int i = n;i>=1;i--) {
		int j = i;
		j = lst[a[j]];
		cnt[j]++;
		if(cnt[j] == 1) vis.push_back(j);
	}
	sort(vis.begin(),vis.end());
	for(auto i : vis) {
		if(flag[i]) continue;
		int sum = 0;
		while(i <= n) {
			if(!flag[i]) sum += cnt[i];
			flag[i] = true;
			num[a[i]] += sum;
			int nxt = lst[a[i+1]];
			i = nxt;
		}
	}
	for(int i = 1;i<=m;i++) cout << num[i] << ' ';
	return 0;
}
