#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2147483647;
const int N = 2e5+5;
int n , m , a[N] , cnt[31] , sum[31] , ans = MAXN;
signed main(){
	freopen("and.in" , "r" , stdin);
	freopen("and.out" , "w" , stdout);
	sum[0] = 1;
	for(int i = 1;i <= 30;i++){
		sum[i] = sum[i - 1] * 2;
	}
	cin>>n>>m;
	m = n - m;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
		a[i] = MAXN - a[i];
		int t = a[i];
		for(int j = 30;j >= 0;j--){
			if(t >= sum[j]){
				cnt[j]++;
				t -= sum[j];
			}
		}
	}
	//for(int i = 1;i <= n;i++){
	//	cout<<a[i]<<' ';
	//}
	//cout<<'\n';
	//for(int i = 0;i <= 30;i++){
	//	cout<<cnt[i]<<' ';
	//}
	//cout<<'\n';
		for(int j = 30;j >= 0;j--){
			if(cnt[j] <= m && cnt[j] >= 0){
				//cout<<j<<'\n';
				ans -= sum[j];
				m -= cnt[j];
				for(int k = 1;k <= n;k++){
					if((a[k] & (MAXN - sum[j])) != a[k]){
						for(int y = 30;y >= 0 && a[k] > 0;y--){
							if(a[k] >= sum[y]){
								cnt[y]--;
								a[k] -= sum[y];
							}
						}
					}
				}
				//cnt[j] = -1;
				//for(int b = 0;b <= 30;b++){
				//	cout<<cnt[b]<<' ';
				//}
				//cout<<m<<'\n';
			}
		}
	cout<<MAXN - ans<<endl;
}
