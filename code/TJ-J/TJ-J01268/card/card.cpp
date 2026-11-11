#include <iostream>
#include <cstdio>
using namespace std;
int a[500001],t = 0,cnt[300001],st[500001],ans[500001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for (int i = 1;i <= n;i++) cin >> a[i];
	if (n <= 500){
		for (int i = 1;i <= n;i++){
			t = 0;
			for (int j = 1;j <= m;j++) cnt[j] = 0;
			for (int j = i;j <= n;j++){
				if (cnt[a[j]] == 0){
					st[++t] = a[j];
					cnt[a[j]] = t;
				}
				else{
					for (int k = cnt[a[j]] + 1;k <= t;k++)
						cnt[st[k]] = 0;
					t = cnt[a[j]];
				}
			}
			for (int j = 1;j <= t;j++) ans[st[j]] += 1;
		}
		for (int i = 1;i <= m;i++) cout << ans[i] << " ";
	}
	else{
		int x = 1;
		for (int i = 1;i <= n;i++){
			if (a[i] != x){
				x++;
				cout << i-1 << " ";
			}
		}
		cout << n;
	}
	return 0;
}
