#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
const int MAXN = 2e5 + 10;
int n,ans,len;
char a;
string s;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> n;
	for(int i = 1;i <= n;++i){
		cin >> len >> a;
		for(int j = 1;j <= len;++j) s.push_back(a);
	} 
	int p = 0,q = s.size() - 1;
	while(p < q){
		ans += s[p] != s[q];
		p++,q--;
	}
	cout << ans;
	return 0;
}
/*
3
2 a
2 b
1 c

2

2 
2 a
3 a

0

6 
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b

3000000000

*/
