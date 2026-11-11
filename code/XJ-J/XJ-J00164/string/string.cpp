#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
string s =  "0";
int size;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		int a;
		string c;
		cin  >> a  >> c;
		size += a;
		for(int i = 1;i <= a;i++){
			s += c;
		}
	}
	int ans=0;
	for(int i = 1;i <= size/2+1;i++){
		if(s[i]  != s[size + 1-i]){
			ans++;
		}
	}
	cout << ans;
	return 0;
}


