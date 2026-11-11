#include <bits/stdc++.h>
using namespace std;
int n,m,a[200010],mx = 0;
string str[200010];
string f(int x){
	string ans = "";
	while(x > 0){
		ans = char('0' + (x % 2)) + ans;
		x /= 2;
	}
	return ans;
}string And(string x,string y){
	int s = max(x.size(),y.size());
	string ans = "";
	while(x.size() < y.size()) x = '0' + x;
	while(x.size() > y.size()) y = '0' + x;
	for(int i = 0;i < s;i++){
		if(x[i] == '1' && y[i] == '1'){
			ans += '1';
		}else{
			ans += '0';
		}
	}
	return ans;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}sort(a + 1,a + n + 1);
	for(int i = n;i > n - m;i--){
		str[i] = f(a[i]);
	}string s = str[n];
	for(int i = n - 1;i > n - m;i--){
		s = And(s,str[i]);
	}int ans = 0,idx = 0;
	if(s == "0"){
		cout << 0;
		return 0;
	}else{
		while(s[idx] == '0') idx++;
	}for(int i = idx;i < s.size();i++){
		ans = ans * 2 + (int)(s[i] - '0');
	}
	cout << ans;
	return 0;
}
