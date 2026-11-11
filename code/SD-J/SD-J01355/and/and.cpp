#include <bits/stdc++.h>
#define ilv inline void
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
using namespace std;

typedef long long ll;

const int N = 200005; 

int n, m, a[N]; 

inline void rd(int &a, int c = 0) {
	while (!isdigit(c = getchar()));
	for (a = 0; isdigit(c); c = getchar()) a = (a << 3) + (a << 1) + (c ^ 48);
}
int check(int k) {
	int c = 0;
	rep(i, 1, n) c += (a[i] & k) == k;
	return c >= m;
}
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	rd(n), rd(m);
	rep(i, 1, n) rd(a[i]);
	int ans = 0;
	per(i, 29, 0) {
		if (check(ans | 1 << i)) ans |= 1 << i;
	}
	cout << ans;
	return 0;
} 
/*
5 3
31 3 1 15 7
*/

/*
万物终归向海 何必衔木石来
月色随风摇摆 我仍飞奔向海
我只是太想要份爱 我只是太想被好好对待 

可是我存在的意义呢
填满我悲欢的执着呢
我明白我心中的海
填满不回来 回来

你与我先谈养心殿
后拜瀑淋身
闲暇问几页 臭读几篇书
也罢 至沉没在大海

今命中万事一字空赴生赴死 亦从容
泼酒入海醉倒天地投身苍穹 万物长拥

所谓有求而不得 人心欲壑
可填沧海 成败不堪一说
如人间过客 总追着虚无漂泊
趟着泪河 沉沦沉默
*/
