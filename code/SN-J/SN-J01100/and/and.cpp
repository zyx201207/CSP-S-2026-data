#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1000005;
const int M = 5005;
int n,m,ans,a[N],maxn,h;
bool check(int s){
	int cnt = 0;
	for(int i = 1;i <= n;i++){
		if((a[i]&s) == s)
			cnt++;
	}
	if(cnt >= m)
		return true;
	return false;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
//	system("fc and.out and5.ans");
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		maxn = max(maxn,a[i]);
	}
	h = log2(maxn)+1;
	for(int i = h;i >= 0;i--){
		int ans2 = ans+(1<<i);
		if(check(ans2))
			ans += (1<<i);
	}
	cout << ans << '\n';
	return 0;
}
/*
CCF Just_do_it.png
Flynewcat
尽管我无法证明它的对错，但我坚信它是对的！ 
*/
