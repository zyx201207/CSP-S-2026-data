#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	string s = " ";
	int m = 0;
	for(int i = 1;i <= n;i++){
		int x;
		cin >> x;
		m += x;
		char c;
		cin >> c;
		for(int j = 1;j <= x;j++){
			s += c;
		}
	}
	int ans1 = 0,ans2 = 0;
//	cout << s << endl;
	for(int i = 1;i <= m/2;i++){
//		cout << i << ' ' << m-i+1 << ' ' << s[i] << ' ' << s[m-i+1] << endl;
		if(s[i] != s[m-i+1]){
			ans1++;
		}
	}
	for(int i = m;i >= m/2+1;i--){
		if(s[i] != s[m-i+1]){
			ans2++;
		}
	}
//	cout << ans1 << ' ' << ans2;
	cout << min(ans1,ans2);
	return 0;
}
