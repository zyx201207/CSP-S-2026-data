#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
const int N = 5e5 + 5;
int n;
LL m;
LL a[N];
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1, [](LL x, LL y){return x < y;});
	int cnt = 1, ans = 1;
	LL sum = 0;
	for(int i = n, j = n; ; ){
		while(sum <= m && 1 < i){
			ans = max(ans, cnt);
			i--;
			sum += a[j] - a[i];
			cnt ++;
		}
		while(m < sum){
			sum -= (a[j] - a[j - 1]) * (cnt - 1);
			cnt --;
			j--;
		}
		ans = max(ans, cnt);
		if(i == 1) break;
	}
	cout << ans;
}