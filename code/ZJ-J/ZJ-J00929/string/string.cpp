#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int cnt[N], pre[N], s[N]; 
char alp[N];
int n;
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> cnt[i] >> alp[i];
	}
	int p = 1, q = n;
	long long ans = 0;
	while(p < q){
		if(alp[p] != alp[q]){
			if(cnt[p] < cnt[q]){
				ans += cnt[p];
				cnt[q] -= cnt[p];
				cnt[p] = 0;
			}else{
				ans += cnt[q];
				cnt[p] -= cnt[q];
				cnt[q] = 0;
			}
		}else{
			if(cnt[p] < cnt[q]){
				cnt[q] -= cnt[p];
				cnt[p] = 0;
			}else{
				cnt[p] -= cnt[q];
				cnt[q] = 0;
			}
		}
		if(cnt[q] == 0) q--;
		if(cnt[p] == 0) p++;
	}
	cout << ans;
	return 0;
}