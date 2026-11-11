#include<bits/stdc++.h>
using namespace std;

int n,m;
long long s[200005];
char ss[200005];
string x;
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> s[i];
		cin >> ss[i];
		m += s[i];
		for(int j = 1;j <= s[i];j++){
			x = x+ss[i];
		}
	}
	for(int i = 0;i < m/2;i++){
		if(x[i] != x[m-i-1]) ans++;
	}
	cout << ans;
	return 0;
}
