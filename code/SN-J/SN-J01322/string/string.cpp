#include <bits/stdc++.h>
using namespace std;
const int maxn = 20110600;
long long a[maxn];
char c[maxn];
long long n, maxnum = 0;
bool special(){
	for(int i = 1; i <= n; i++) if(c[i] != c[1]) return false;
	return true;
}
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	string s;
	char maxc;
	while(n--){
		int i = 1;
		cin >> a[i] >> c[i];
		if(a[i] > maxnum){
			maxnum = a[i];
			maxc = c[i];
		}
		for(int j = 1; j <= a[i]; j++) s += c[i];
		i++;
	}
	if(special()){ cout << 0; return 0;}
	long long ans = 0;
	for(size_t i = 0; i < s.size(); i++){
		if(s[i] != maxc){
			ans++;
		}
	} 
	cout << ans;
	return 0;
} 

