#include <bits/stdc++.h>
using namespace std;
const int maxn = 5000010;
const int maxm = 300010;
int st[maxn], a[maxn], num[maxm], top, ans[maxm];
int n, m;
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++){
		cin >> a[i];
	}
	for (int j = 1; j <= n; j ++){
		top = 0;
		for (int i = j; i <= n; i ++){
			if (num[a[i]]){
				for (; st[top] != a[i]; top --){
					num[st[top]] --;
				}
			}else{
				st[++ top] = a[i];
				num[a[i]] ++;
			}
		}
		for (int j = 1; j <= top; j ++){
			ans[st[j]] += 1;
			num[st[j]] = 0;
			st[j] = 0;
		}
	}
	
	for (int i = 1; i <= m; i ++){
		cout << ans[i] << " ";
	}
	return 0;
} 
