#include <bits/stdc++.h>
using namespace std;
#define int long long
//76 pts
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	string s;
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin >> a >> c;
		s+=string(a,c);
	}
	int Lens=s.size();
	int cnt=0;
	for(int i=0;i<=Lens/2-1;i++){
		if(s[i]!=s[Lens-i-1]){
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}
