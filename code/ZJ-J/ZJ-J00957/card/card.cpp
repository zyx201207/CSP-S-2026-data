#include<bits/stdc++.h>
using namespace std;
int n, m, a[500005], k[100005], pos[500005], cnt[100005];
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i=1; i<=n; i++){
		cin >> a[i];
		pos[a[i]]=i;
	}
	for(int i=1; i<=n; i++){
		for(int j=i; j<=n; j++){
			cnt[a[j]]++;
			int k=pos[a[j]];
			j=k;
		}
	}
	for(int i=1; i<=m; i++){
		cout << cnt[i] << " ";
	}
	return 0;
}
