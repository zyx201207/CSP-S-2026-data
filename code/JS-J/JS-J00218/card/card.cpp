#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m, cnt1 = 0, cnt2 = 0; 
	bool t = 0;
	cin >> n >> m;
	int a[n + 5], b[n + 5] = {}, c[m + 2] = {};
	for(int i = 1; i <= n; i++){
	    cin >> a[i];
	    b[i] = 0;	
	}for(int i = 1; i <= n; i++){
		cnt1 = 0;
		cnt2 = 0;
		for(int j = i; j <= n; j++){
			t = 0;
			cnt2 = cnt1;
			for(int k = 1; k <= cnt1; k++){
			    if(a[j] == b[k]){
					t = 1;
				} if(t){
					b[k] = 0;
					cnt2--;
				}
			}cnt2++; 
			cnt1 = cnt2;
			b[cnt1] = a[j];
		}for(int j = 1; j <= m; j++){
			for(int k = 1; k <= cnt1; k++){
				if(b[k] == j){
					c[j]++;
				}
			}
		} 
	} for(int i = 1; i <= m; i++){
		cout << c[i] << " ";
	}
	return 0;
}
