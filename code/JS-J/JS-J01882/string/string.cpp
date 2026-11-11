#include <bits/stdc++.h>
using namespace std;
long long n,ans;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    while (n--){
		int x;
		char y;
		cin>>x>>y;
		while (x--) s += y;
	}
	for (size_t i = 0;i < (s.size()+1)/2;i++){
		if (s[i] != s[s.size()-1-i]) ans++;
	}
	cout<<ans;
    return 0;
}
