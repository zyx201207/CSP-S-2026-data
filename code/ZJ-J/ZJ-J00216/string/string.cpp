#include <bits/stdc++.h>
using namespace std;
long long n, mx, gc;
struct ch{
	long long num;
	char c;
}a[200005];
long long sum, ans;
string add(int x){
	string i;
	long long u = a[x].num;
	while (u){
		i += a[x].c;
		u--;
	}return i;
}string sr(){
	string st ="";
	for (int i = 1;i <= n;i++){
		st += add(i);
	}return st;
}bool check(string a){
	string c;
	reverse(a.begin(), a.end());
	c = a;
	reverse(a.begin(), a.end());
	return c == a;
}int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1;i <= n;i++){
		cin >> a[i].num >> a[i].c;
		if (a[i - 1].c == a[i].c){
			a[i - 1].num += a[i].num;
			n--;
			i--;
		}mx = max(mx, a[i].num);
	}if (n == 1){
		cout << 0;
		return 0;
	}gc = a[1].num;
	for (int i = 2;i <= n;i++){
		gc = __gcd(gc, a[i].num);
	}for (int i = 1;i <= n;i++){
		a[i].num /= gc;
	}string str = sr();
	reverse (str.begin(), str.end());
	string str2 = str;
	for (int i = 0;i < str.size();i++){
		if (str[i] != str2[i]){
			swap(str[i], str2[i]);
			ans++;
		}if (check(str) && check(str2)){
			break;
		}
	}cout << max(1LL, ans) * gc;
	return 0;
}