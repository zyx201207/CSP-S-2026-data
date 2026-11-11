#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],mp[500005],ans[500005],f[500005];
bool f1[500005];
int main(){
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=1;i<=n;i++){
		memset(mp,0,sizeof(mp));
		memset(f,0,sizeof(f));
		memset(f1,0,sizeof(f1));
		int x = 1;
		for(int j=i;j<=n;j++){
			if(!f[a[j]]) {
				mp[x] = a[j];
				f[a[j]] = x++;
			}else {
				int fu = f[a[j]];
				for(int k=f[a[j]];k<x;k++) {
					f[mp[k]] = 0;
					mp[k] = 0;
				}
				x = fu + 1;
				mp[x-1] = a[j];
				f[a[j]] = x-1;
			}
		}
		for(int j=1;j<=x;j++) {
			if(!f1[mp[j]]) {
				ans[mp[j]]++;
				f1[mp[j]] = 1;
			}
		}
	}
	for(int i=1;i<=m;i++) cout << ans[i] << " ";
	return 0;
}
