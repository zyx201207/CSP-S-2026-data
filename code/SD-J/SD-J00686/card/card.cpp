#include<bits/stdc++.h>

using namespace std;
#define int long long

int a[505],d[305],b[505];
map<int,int> mp;
map<int,int> ans; 
bool f[5005];

signed main(){

	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	int n,m; 
	cin >> n >> m;
	for(int i = 1;i <= n; ++ i) {
		cin >> a[i];
		//b[i] = a[i];
	}
	for(int i = 1;i <= n; ++ i) {
		mp.clear();
		ans.clear();
		memset(f,false,sizeof f);
		//memset(f,false,sizeof f);
		for(int j = 1;j <= n; ++ j) b[j] = 0;
		for(int j = i;j <= n; ++ j) {
			if(mp[a[j]] != 0) {
				if(b[mp[a[j]]] != -1) {
				b[mp[a[j]]] = -1;
				b[j] = -2;}
				mp[a[j]] = j;
			} else {
				mp[a[j]] = j;
			}
		}
		int cnt = 0;
		for(int j = i;j <= n; ++ j) {
			if(b[j] == -1) cnt ++;
			if(b[j] == -2) cnt --;
			if(cnt == 0 && f[a[j]] == false) {
				ans[a[j]] ++;
				f[a[j]] = true;
			}
			//cout << b[i] << " ";
		}
	}
	for(int i = 1;i <= m; ++ i) cout << ans[i] << " ";

	return 0;
}

