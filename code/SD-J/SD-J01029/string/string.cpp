#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 2e5+10;
pair<long long,char> p[N];
int n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >>n;
	for (int i = 1;i <= n;i++){
		cin >> p[i].first >> p[i].second;
		if (i != 1 && p[i].second == p[i-1].second){
			p[i-1].first += p[i].first;
			n--,i--;
		}
	}
	string s;
	for (int i = 1;i <= n;i++){
		s += string(p[i].first,p[i].second);
	}
	LL ans = 0;
	LL m = s.size();
	s = " " + s;
	for (int i = 1;i <= m;i++){
		if (s[i] != s[m-i+1]){
			ans++;
			s[i] = s[m-i+1];
		}
	}
	cout << ans <<"\n";
	return 0;
}
