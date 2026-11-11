#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const string FILE_PRE = "crystal";
/*
1. freopen
2. long long
3. cerr
4. 多测清空
5. 交卷前删无关文件 
*/
int n;
ll m, a[500005];
// 桌面是不是太小了
// Oct31==Dec25? 是hyw 
int ans = 1;
/*
O(n log n) 枚举+二分？
先排序，枚举i，维护a_j加到a_i所需操作数d_j，然后把d后缀和一下得到s，在s里二分查找<=m最大值位置
i++后d[j]+=a[i]-a[i-1],s[j]+=(i-j)*(a[i]-a[i-1])
坏了不会要上线段树吧 那就得是O(n log^2 n)了 
孩子们我把区间加等差数列线段树忘了
哦没有区间和查询，直接leafy(?) 
*/ 
struct node{
	int l, r; 
	ll val, sx, gc;
	void upd(ll s, ll d){
		if(l == r) val += s;
		else sx += s, gc += d;
	}
} tr[2000005];
void build(int p = 1, int l = 1, int r = n){
	tr[p].l = l, tr[p].r = r, tr[p].val = (l == r ? 0 : LLONG_MIN);
	if(l < r){
		int mid = (l + r) >> 1;
		build(p << 1, l, mid);
		build(p << 1 | 1, mid + 1, r);
	}
}
void pushdown(int p){
	tr[p << 1].upd(tr[p].sx, tr[p].gc);
	tr[p << 1 | 1].upd(tr[p].sx + tr[p].gc * (tr[p << 1 | 1].l - tr[p].l), tr[p].gc);
	tr[p].sx = tr[p].gc = 0;
}
void update(int i, int p = 1){
	if(tr[p].l >= i) return;
	if(tr[p].r < i){	
		tr[p].upd((a[i] - a[i-1]) * (i - tr[p].l), a[i-1] - a[i]);
		return;
	}
	pushdown(p);
	update(i, p << 1);
	update(i, p << 1 | 1);
}
ll qry(int i, int p = 1){
	if(tr[p].l == tr[p].r && tr[p].r == i) return tr[p].val;
	else{
		pushdown(p);
		if(i <= tr[p << 1].r) return qry(i, p << 1);
		return qry(i, p << 1 | 1);
	}
}
void solve(int i){
	update(i);
	int l = 1, r = i - 1, res = i;
	while(l <= r){
		int mid = (l + r) >> 1;
		if(qry(mid) <= m) res = min(res, mid), r = mid - 1;
		else l = mid + 1;
	}
	ans = max(ans, i - res + 1);
}

#ifdef __linux__
#define gc() getchar_unlocked()
#else
#define gc() _getchar_nolock()
#endif
ll getll(){
	ll x = 0; char ch = gc(); bool f = 0;
	while(!isdigit(ch)) f |= (ch == '-'), ch = gc();
	while(isdigit(ch)) x = x * 10 - '0' + ch, ch = gc();
	return (f ? -x : x);
}
int main(){
	freopen((FILE_PRE+".in").c_str(), "r", stdin);
	freopen((FILE_PRE+".out").c_str(), "w", stdout);
	
	n = getll(), m = getll();
	for(int i = 1; i <= n; i++) a[i] = getll();
	sort(a + 1, a + n + 1);
	build(); // 忘建树了没绷住 
	for(int i = 1; i <= n; i++)
		solve(i);
	cout << ans << endl;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
// 拼尽全力无法卡进本地 1s，少爷机一定要发力啊 
// 用时：1.5h，期望得分：[45, 100]pts 
