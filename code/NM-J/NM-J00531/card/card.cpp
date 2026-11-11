#include<bits/stdc++.h>
using namespace std;
int n, m;
int a[200010];
int ans[200010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++){
		bool b[200010]; 
		for(int j = i; j <= n; j++){
			if(b[a[j]] == 0) {
				b[a[j]] = 1;
			}
			else {
				for(int l = 1; l <= m; l++) b[l] = 0;
				b[a[j]] = 1;
			}
		}
		for(int j = 1; j <= m; j++) if(b[j] == 1) ans[j] ++;
	} 
	for(int i = 1; i <= m; i++){
		cout << ans[i] << " ";
	}
    fclose(stdin);
	fclose(stdout);
	return 0;
} 
