#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, len, len2, len3, asn; pair<int, char> ac[200005]; char smalluse[10000005];
void big(), small();
signed main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> ac[i].first >> ac[i].second;
		len += ac[i].first;
	}
	if(len > 10000000) big();
	else small();
	return 0;
}
void big(){
	int l = 1, r = n;
	while(l < r){
		len2 += ac[l].first;
		while(len3 <= len2){
			len3 += ac[r].first;
			if(len3 > len2){
				if(ac[r].second != ac[l].second) asn += len3 - (len3 - len2) - (len3 - ac[r].first);
				l++; break;
			}
			if(ac[r].second != ac[l].second) asn += min(ac[l].first, ac[r].first);
			r--;
		}
	}
	cout << asn;
}
void small(){
	int j = 1;
	for(int i = 1; i <= n; i++){
		int k = j + ac[i].first - 1;
		for(; j <= k; j++) smalluse[j] = ac[i].second;
	}
	for(int i = 1; i <= len / 2; i++) if(smalluse[i] != smalluse[len + 1 - i]) asn++;
	cout << asn;
}
