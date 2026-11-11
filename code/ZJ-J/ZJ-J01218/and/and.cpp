#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

#define int long long

struct Node{
	int son[2];
	int v;
};

int n, m, a[200005];
std::vector<Node> tr;

int neww(){
	tr.push_back({{0, 0}, 0});
//	printf("%lld\n", tr.size() - 1);
	return tr.size() - 1;
}

void add(int x, int maxx){
	int now = 0;
	for(int i = maxx;i >= 0;i--){
		int xx = (x >> i) & 1;
//		printf("%lld %lld %lld\n", x, i, xx);
		if(!tr[now].son[xx]){
			int xxx = neww();
			tr[now].son[xx] = xxx;
//			printf("%lld %lld\n", xx, tr[now].son[xx]);
		}
		now = tr[now].son[xx];
		tr[now].v++;
	}
}

int ask(int maxx){
	int now = 0, need = m, res = 0;
	for(int i = maxx;i >= 0;i--){
		if(!tr[now].son[1]){
			now = tr[now].son[0];
			continue;
		}
		if(tr[tr[now].son[1]].v >= need)
			res |= (1 << i), now = tr[now].son[1];
		else
			now = tr[now].son[0];
//		printf("%lld\n", res);
	}
//	if(need)
//		res &= tr[now].num;
	return res;
}

signed main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	tr.push_back({{0, 0}, 0});
	scanf("%lld%lld", &n, &m);
//	printf("%lld", n);
	int tmp = 0;
	for(int i = 1;i <= n;i++)
		scanf("%lld", &a[i]);
	for(int i = 31;i >= 0;i--){
		int num = 0;
		for(int j = 1;j <= n;j++)
			num += (a[j] >> i) & 1;
		if(num >= m){
			tmp = i;
			break;
		}
	}
//	printf("%lld\n", tmp);
	for(int i = 1;i <= n;i++)
		add(a[i], tmp);
	tr[0].v = n;
	printf("%lld", ask(tmp));
	return 0;
}