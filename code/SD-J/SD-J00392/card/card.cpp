#include <bits/stdc++.h>
using namespace std;
int a[100005],b[10000005];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 1;i<=n; i++) cin >> a[i];
	for(int i = 1;i<=n; i++){
		int cnt[500005] = {0};
		for(int j = i; j<=n; j++){
			if(cnt[a[j]] > 0){
				int q;
				for(int k = i; k<j; k++){
					if(a[k] == a[j]){
						q = k;
					}
				}
				//cout << q << " " << j << endl;
				
				for(int k = q; k<j;k++) {
					//cout << a[k] << " ";
					cnt[a[k]] = 0;
				}
				//cout << endl;
			}
			cnt[a[j]]++;
		}
		for(int j = 1;j<=m; j++){
			if(cnt[j] > 0) b[j]++;
		}
	}
	for(int i = 1;i<=m; i++) cout << b[i] << " ";
	return 0;
}
