#include<bits/stdc++.h>
using namespace std;
int cd[500010],k[500010],ans[300010];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	bool f = 1;
	for(int i = 1; i <= m; i++){
		ans[i] = 0;
	}
	for(int i = 1; i <= n; i++){
		cin >> cd[i];
		k[i] = 0;
		if(cd[i] != cd[i+1]){
			f = 0;
		}
	}if(!f){
		for(int i = 1; i <= m; i++){
			if(i == cd[i]){
				cout << n << " ";
			}else{
				cout << "0 ";
			}
		}
	}else{
		int u;
		for(int i = 1; i <= n; i++){
			int ac = cd[i],l = 0;
			for(int j = 1; j <= n; j++){
				if(cd[j] == ac){
					if(j == n){
						l++;
						k[l] = cd[j];
					}else{
						for(int p = 1; p <= j; p++){
							l++;
							k[l] = cd[i];
						}
					}
				}
			}
			for(u = 1; u <= m; u++)
				for(int j = 1; j <= l; j++){
					if(u == k[j]){
						ans[u] += u;
					}
				}
		}
		for(int i = 1; i <= m; i++){
			cout << ans[i] << " "; 
		}
	}
	return 0;
}
