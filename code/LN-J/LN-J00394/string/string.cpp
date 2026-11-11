#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	string s;
	int n;
	cin >> n;
	while(n--){
		int a;
		char c;
		cin >> a >> c;
		for(int i=1; i<=a; i++) s+=c;
	}
	
	int ans=0;
	
	for(int i=0,j=s.size()-1; i<j; i++,j--){
		if(s[i]!=s[j])
			ans++;
	}
	
	cout << ans << endl;
	return 0;
}


