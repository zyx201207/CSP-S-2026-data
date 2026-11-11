#include <bits/stdc++.h>
using namespace std;

#define int long long
int n, ans, cnt;
string final;
signed main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> n;
	final += " ";
	while(n --){
		int x;
		char s;
		cin >> x >> s;
		cnt += x;
		while(x --) final += s;
	}
	
	for(int i = 1; i <= final.size() / 2; i ++){
		if(final[i] == final[cnt + 1 - i]) continue;
		else ans ++;
	}
	cout << ans << endl;
	
	return 0;
}
