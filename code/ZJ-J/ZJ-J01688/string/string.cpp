#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mn=2e5+10;
int n,len,ans;
string s;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin >> a >> c;
		len+=a;
		for(int j=1;j<=a;j++){
			s+=c;
		}
	}
	for(int i=0;i<(len+1)/2;i++){
		if(s[i]!=s[len-1-i]) ans++;
	}
	cout << ans;
	return 0;
}
