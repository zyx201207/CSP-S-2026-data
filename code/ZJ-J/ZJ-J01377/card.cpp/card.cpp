#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 10;
int n,m,a[N],t[N],cnt[N],loc[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++) cin >> a[i];
	for (int i = 1;i <= m;i++) cnt[i] = n;
	for (int i = 1;i <= n;i++){
		int num;
		memset(t,0,sizeof t);
		memset(loc,0,sizeof loc);
		for (int j = i;j <= n;j++){
			t[a[j]]++;
			if (t[a[j]] == 1) loc[a[j]] = j;
			if (t[a[j]] >= 2){
				for (int k = loc[a[j]] + 1;k <= j;k++){
					cnt[k]--;
				}
				loc[a[j]] = j;
			}
		}
	}
	for (int i = 1;i <= m;i++) cout << cnt[a[i]] << ' ';
	fclose(stdin);
	fclose(stdout);
	return 0;
}
