#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5+10;
int n, m;
int a[N], num[N], ans[N], s[N], vis[N];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	int hh = 1;
	for(int t = 1; t <= n; t++){
		hh = 1;
		fill(num, num+n+1, 0);
		for(int i = t; i <= n; i++){
			if(num[a[i]]){
				hh = min(hh, num[a[i]]);
			}
//			cout << a[i] << " " << hh-1 << "\n";
			num[a[i]] = hh;
			s[hh++] = a[i];
		}
		for(int i = 1; i < hh; i++)
		{
//			cout << s[i] << " ";
			ans[s[i]]++;
		}
//		cout << "\n";
//		for(int i = 1; i <= m; i++){
//			cout << ans[i] << " ";
//		}	
//		cout << "\n";
	}
	for(int i = 1; i <= m; i++){
		cout << ans[i] << " ";
	}
	return 0;
}


