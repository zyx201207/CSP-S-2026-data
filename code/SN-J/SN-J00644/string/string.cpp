//李思奇 83中学 SN-J00644 
#include <bits/stdc++.h>
using namespace std;

string s;
int n,x,ans;
char c;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> x >> c;
		for(int j = 1;j <= x;j++){
			s += c;
		}
	}
	cout << s;
	int len = s.size();
	for(int i = 0;i < len/2+1;i++){
		if(s[i] != s[len-i-1]) ans++;
	}
	cout << ans;
}
