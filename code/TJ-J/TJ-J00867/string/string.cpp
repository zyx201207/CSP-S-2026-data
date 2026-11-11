#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long al = 0,ar = 0,m;
	string s;
	cin >> n;
	while (n--){
		string c;
		int a;
		cin >> a >> c;
		for (int i = 0;i < a;i++){
			s += c;
		}
		m += a;
	}
	long long l = 0,r = m-1;
	while (l < r){
		if (s[l] != s[r]){
			al++;
			ar++;
		}
		l++;
		r--;
	}
	cout << min(al,ar) << "\n";
	return 0;
}
