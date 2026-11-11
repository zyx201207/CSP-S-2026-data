#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5e5 + 10;
int n, m, a[N], t[N], ans[N];
signed main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n;i ++) {
    	cin >> a[i];
    	t[a[i]] = i;
	}
	//for(int i = 1;i <= m;i ++) cout << t[i] << " ";
    for(int i = 1;i <= n;i ++){
    	for(int j = i;j <= n;j ++){
    		ans[a[j]] ++;
    		j = t[a[j]];
		}
	}
	for(int i = 1;i <= m;i ++) cout << ans[i] << " ";
    return 0;
}
//2026 csp j/s rp ++;