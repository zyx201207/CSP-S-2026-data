#include <bits/stdc++.h>
using namespace std;
int n;
int a;
char c;
string s;
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a >> c;
		for(int j = 1;j <= a;j++){
			s+=c;
		}
	}
	int l = s.size();
	for(int i = l/2;i <= l;i++){
		if(s[i] != s[l-i-1]) ans++;
	}
	cout << ans << '\n';
	return 0;
}
