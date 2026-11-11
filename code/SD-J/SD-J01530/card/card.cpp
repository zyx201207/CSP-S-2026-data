#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N = 5e5 + 10;

ll n, a[N], m, res[N], b[N], q[N], lst[N], L = 1, R = 0, is[N];
// b[k] 点数为 k 的牌最后一次出现的下标  q,tail 手写队列 

void solve(ll st) {
	ll tail = 0;
	for (ll i = 1; i <= n; i ++) b[a[i]] = 0;
	
	for (ll i = st; i <= n; i ++) {
		if (!b[a[i]]) 
			q[++ tail] = a[i];
		else 
			while (tail > b[a[i]]) b[q[tail --]] = 0;
		b[a[i]] = tail;
	}
	for (ll i = 1; i <= tail; i ++) res[q[i]] ++;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);

	cin >> n >> m;
	
	if (n <= 5000)  {
		for (ll i = 1; i <= n; i ++) cin >> a[i];
		for (ll i = 1; i <= n; i ++) solve(i);	// O(n^2) 48pts
	
		for (ll i = 1; i <= m; i ++) cout << res[i] << ' ';
	}
	else {	// 我的正解大约的确是写寄了 样例没过 
		for (ll i = 1; i <= n; i ++) {
			cin >> a[i];	
			lst[a[i]] = i;
		}
		for (ll i = n - 1; i >= 1; i --) {
			if (lst[a[i]] > i && lst[a[i]] > R) R = lst[a[i]], L = i;
		}
		
		for (ll i = 1; i <= n; i ++) {
			if (is[a[i]]) continue;
			if (lst[a[i]] > L && lst[a[i]] < R) res[a[i]] += lst[a[i]] - L;
			else if (lst[a[i]] < L || lst[a[i]] >= R) res[a[i]] += lst[a[i]];
			is[a[i]] = 1;	// a[i] 被统计过答案了 
		}
	
		for (ll i = 1; i <= m; i ++) cout << res[i] << ' ';
	}
	return 0;
}

// 刚看到这题没啥想法 先写个模拟 
// 你敢信我模拟写了快 half an hour 我是 【数据删除】 
// 我的“正解”连样例都没过，我是 【数据删除】   离结束还有20min
// 可惜我最后还是没 AK 

// 事已至此，先唱歌吧
// 英语不好 凭模糊的记忆写的 《Bloom》 

// I thought a new day would come
// believed hope would save me
// Wanted to live in a place without anyone's mind

// That ... clumbed with a thud
// In face of death, changed way of life
// So don't need to be afraid, think only own finding way ...
// No crying

// Tell me how the fact
// 
// I can only turn away by laughing, and fooling round(?)

// Will this urging within me grow bigger someday?
// It wasn't magic as I knew it

// 二周目忘词了

// I hear the clock tick tock
// Where is the ending you desired?
// I look for it
// by whatever nessary （这个【数据删除】怎么老忘词啊） 

// Tell me how the fact
// I just can't lose hope
// I don't want your kindness to end up meaningless
// I tell last many lies as need to
// I'm not afraid
// Is this the magic?

// I just find hope
// I try to save you
// Forgiven even if it's the way that crowl to you
// Now I'll let your heart bloom
// Don't be afraid

// Try closing your eyes
// I'm always be with you………… 
