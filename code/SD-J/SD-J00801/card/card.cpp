#include <bits/stdc++.h>
using namespace std;
#define int long long
#define LYT ios::sync_with_stdio(0),cin.tie(0)
const int N = 5e5 + 10;
int n,m,a[N],t[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i =1;i<=n;i++) cin>>a[i];
	for(int i = 1;i <= m;i++){
		int ans = 0;
		for(int j = 1;j <= n;j++){
			stack <int> sta;
			for(int k = j;k <= n;k++){
				if(t[a[k]] == 0) t[a[k]] = 1;
				else{
					while(sta.top() != a[k]) sta.pop();
					sta.pop();
				}
				sta.push(a[k]);
			}
			while(!sta.empty()){
				if(sta.top() == i) ans++;
				sta.pop();
			}
		}
		cout << ans << " ";
	}
	return 0;
}
/*
4 3
1 2 1 3
*/
