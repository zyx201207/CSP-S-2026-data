#include<bits/stdc++.h>
using namespace std;

int n, a[200005], ans;
string s = " ", c = " ";

int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i] >> c[i];
		
		string st = "";
		st += c[i];
		while(st.size()*2 <= a[i]){
			st += st;
		}
		for(int j=1;j<=a[i]-st.size();j++){
			st += c[i];
		}
		s += st;
	}
	long long len = s.size()-1;
	for(int i=1;i<=len/2;i++){
		if(s[i] != s[len+1-i]){
			ans++;
		}
	}
	cout << ans;
	
	return 0;
}
