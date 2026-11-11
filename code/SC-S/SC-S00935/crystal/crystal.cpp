#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int N = 5e5 + 5;
LL m, n;
int ans;
LL num[N], sum[N];
//我从山中来 带着兰花草 家中无富贵 口袋无财宝
//都是同龄人我原本没想降维打击
//我叫水神三 爱玩五影班 技术暗部三 贡丸有黑般 长得像块砖 
//万蛇的撕咬加上毒液的侵蚀 这个斩杀线算的太妙
//天不生我edg vctcn万古如长夜

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for(int i = 1; i <= n; i++) scanf("%lld", &num[i]);
	sort(num + 1, num + 1 + n);	//in -> ax
	for(int i = 1; i <= n; i++) sum[i] += sum[i - 1] + num[i];
	for(int i = 1; i <= n; i++) {
		int l = 1, r = i;
		int mid = (l + r) >> 1;
		while(l < r) {
			if((num[i] * (LL)(i - mid + 1)) - (sum[i] - sum[mid - 1]) <= m) r = mid;
			else l = mid + 1;
			mid = (l + r) >> 1;
		}
		ans = max(ans, (i - mid + 1));
	}
	printf("%d", ans);
	return 0;
}