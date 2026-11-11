#include<bits/stdc++.h>
using namespace std;
int n, m, a[40000009],q[40665401], ans[54616146];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)cin >> a[i];
	for(int i = 1;i <= n;i++){
		int k = 0;
		for(int j = i;j <= n;j++){
			bool l = 0;
			int s;
			for(int r = 1;r <= k;r++){
				if(a[j] == q[r]){
					l = 1;
					s = r;
					break;
				}
			}
			
			if(l == 1){
				k = s;
			}
			if(l == 0)q[++k] = a[j];
		}
		for(int j = 1;j <= k;j++){
			ans[q[j]]++;
			q[j] = 0;
		}
	}
	for(int i = 1;i <= m;i++)cout << ans[i] << ' ';
	return 0;
}
