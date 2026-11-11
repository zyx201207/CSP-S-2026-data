#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,cnt[300010],a[500010];
vector<int>v;
bool vis[500010],spe_a=1;
void solve(){
	cin >> n >> m;
	for (int i=1;i<=n;i++){
		cin >> a[i];
		if (spe_a&&a[i]<a[i-1]) spe_a=0;
	}
	if (spe_a){
		for (int i=n;i>=1;i--){
			cnt[a[i]]=i;
			while (a[i]==a[i-1]) i--;
		}
	}else{
		for (int i=1;i<=n;i++){
			vector<int>vis(n+1,0);
			for (int j=i;j<=n;j++){
				if (vis[a[j]]){
					while (v.back()!=a[j]){
						vis[v.back()]=0;
						v.pop_back();
					}
				}else v.push_back(a[j]),vis[a[j]]=1;
			}
			while (!v.empty()){
				cnt[v.back()]++;
				v.pop_back();
			}
		}
	}
	for (int i=1;i<=m;i++){
		cout << cnt[i] << " ";
	}
	cout << endl;
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int T=1;
//	cin >> T;
	while (T--){
		solve();
	}
	return 0;
}

