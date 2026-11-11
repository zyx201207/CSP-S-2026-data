#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 200010;
int n,m,ans;
int a[N];
bool vis[N];
void t(){
	for(int i = 1 ; i <= n ; i ++)
		cout << vis[i] << ' ';
	cout << "\n\n";
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i ++) cin >> a[i];
	for(int k = 32 ; k >= 0 ; k --){
		int cnt = 0;
		for(int i = 1 ; i <= n ; i ++){
			if(vis[i] == 1) continue;
			if( ((a[i] >> k) & 1LL) ) cnt ++;
		}
		if(cnt < m) continue;
		for(int i = 1 ; i <= n ; i ++)
			if( ((a[i] >> k) & 1) == 0) vis[i] = 1;
	}
	//t();
	bool flag = 0;
	for(int i = 1 ; i <= n ; i ++)
		if(vis[i] == 0){
			if(flag == 0) ans = a[i],flag = 1;
			else ans = (ans & a[i]);
		}
	cout << ans;
	return 0;
}
//RP ++
//Luogu @zzhengxi
