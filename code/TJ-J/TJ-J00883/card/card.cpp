#include <bits/stdc++.h>
using namespace std;
const int N = 5 * 1e5 + 5;
const int M = 3 * 1e5 + 5;
int n,m;
int a[N];
int t[M],b[M];//t来判断有没有a[i]  b来存上一个a[i]的下标 
int ans[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n; i++) cin >> a[i];
	for(int k = 1;k <= n; k++){//第k局游戏 
		memset(t,0,sizeof(t));
		memset(b,0,sizeof(b));
		for(int i = k;i <= n; i++){
			if(t[a[i]] == 0){
				b[a[i]] = i;
				t[a[i]] = 1;
			}
			else if(t[a[i]] == 1){
				for(int j = b[a[i]];j < i; j++){
					t[a[j]] = 0;
					b[a[j]] = 0;
				}
				t[a[i]] = 1;
				b[a[i]] = i;
			}
		}
		for(int i = 1;i <= m; i++){
			if(t[i] == 1){
				ans[i]++;
			}
		}
	}
	for(int i = 1;i <= m; i++) cout << ans[i] << ' ';
	return 0;
}
/*
4 3
1 2 1 3

10 3
3 1 2 1 3 2 3 1 2 1
*/
