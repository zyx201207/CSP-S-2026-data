#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans;
string s,c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	while(n--){
		cin >> m >> c;
		for(int i = 1;i <= m;i++)s += c;
	}
	for(int i = 0,j = s.size() - 1;i <= j;i++,j--)
		if(s[i] != s[j])
			ans++;
	cout << ans;
	return 0;
}
/*
1

3
2 a
2 b
1 c

2
 * 
2

2
2 a
3 a

0
 * 
3

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b

3000000000
*/
