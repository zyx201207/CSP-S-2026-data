#include<bits/stdc++.h>
using namespace std;
constexpr int N = 5e5 + 10;
int n,cnt,ans;
char a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		int x;
		cin >> x;
		char s;
		cin >> s;
		for(int j = 1;j <= x;j++){
			cnt++;
			a[cnt] = s;
		}
	}
	for(int i = 1;i <= cnt / 2;i++){
		if(a[i] != a[cnt - i + 1]) ans++;
	}
	cout << ans;
	return 0;
}