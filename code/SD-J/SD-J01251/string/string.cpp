#include <bits/stdc++.h>
#define int long long

using namespace std;

int n, ans;
struct info{
	int len;
	char s;
} a[200001];

signed main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i].len >> a[i].s;
	int pos1 = 1, pos2 = n;
	while (pos1 < pos2){
		if (a[pos1].s == a[pos2].s){
			if (a[pos1].len == a[pos2].len)
			    pos1++, pos2--;
			else if (a[pos1].len < a[pos2].len)
			    a[pos2].len -= a[pos1].len, pos1++;
			else
			    a[pos1].len -= a[pos2].len, pos2--;
		}
		else {
			if (a[pos1].len == a[pos2].len)
			    ans += a[pos1].len, pos1++, pos2--;
			else if (a[pos1].len < a[pos2].len)
			    ans += a[pos1].len, a[pos2].len -= a[pos1].len, pos1++;
			else
			    ans += a[pos2].len, a[pos1].len -= a[pos2].len, pos2--;
		}
	}
	cout << ans << endl;
}//有点神秘，应该100
//求你了CCF，give me1=  
