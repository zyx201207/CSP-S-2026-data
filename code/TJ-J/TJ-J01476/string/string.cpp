#include<bits/stdc++.h>
using namespace std;

int main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s = "";
	int n;
	cin >> n;

	for(int i=1;i<=n;i++){
		int x;
		char c;
		cin >> x >> c;
		
		while(x--){
			s += c;
		}
	}//∂¡»Î
	
	if(n == 1){
		cout << 0;
		return 0;
	}
	//À´÷∏’Î
	
	int l = 0;
	int r = s.size()-1;
	int ans = 0;
	
	while(l < r){
		if(s[l] == s[r]){
			l++;
			r--;
			continue;
		}
		
		ans++;
		l++;
		r--;
	} 
	cout << ans;

	
	
	
	
	return 0;
} 
