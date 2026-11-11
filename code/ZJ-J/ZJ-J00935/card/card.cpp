#include<bits/stdc++.h>
using namespace std;

int n, m, a[500005], ans[500005];

int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1;i<=n;i++){
		vector<int> x(500005, 0);
		vector<int> set(500005, 0);
		for(int j=i;j<=n;j++){
			if(x[a[j]] == 0){
				x[a[j]]++;
				set[a[j]] = j;
			}
			else{
				for(int k=j;k>=set[a[j]];k--){
					x[a[k]]--;
				}
			}
		}
		for(int j=1;j<=m;j++){
			if(x[j])
				ans[j]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout << ans[i] << " ";
	}
		
	return 0;
}
