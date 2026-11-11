#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500005];
int b[500005];
int ans[300005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)cin >> a[i];
	for (int i = 1;i <= n;i++){
		for (int j = i;j <= n;j++){
			b[j] = a[j];
			for (int l = j-1;l >= 1;l--){
				if (b[j] == b[l]){
					for (int k = l;k <= j-1;k++){
						b[k] = -1e9;
					}
				}
			}
			
		}
		for (int j = 1;j <= m;j++){
			for (int l = i;l <= n;l++){
				if (b[l] == j)ans[j]++;
			}
		}
	}
	for (int i = 1;i <= m;i++)cout << ans[i]<< " ";
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
