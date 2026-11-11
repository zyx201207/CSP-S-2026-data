#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n,m;
int a[N],ans[N],b[N],cnt[N][2];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;++i) cin >> a[i];
	int e;
	for(int i = 1;i <= n;++i){
		e = 1;
		cnt[a[i]][0] = cnt[a[i]][1] = 0;
		for(int j = 1;j <= m;++j) cnt[j][0] = 0;
		for(int j = i;j <= n;++j){
			if(cnt[a[j]][0]){
				for(int k = cnt[a[j]][1];k < j;++k) cnt[a[k]][0] = 0;
				e = cnt[a[j]][1];
			}
			b[e] = a[j];
			cnt[a[j]][0] = 1;
			cnt[a[j]][1] = e;
			e++;
		}
		for(int j = 1;j <= m;++j){
			ans[j] += cnt[j][0];
		}
	}
	for(int i = 1;i <= m;++i){
		cout << ans[i] << " ";
	}
	return 0;
}
