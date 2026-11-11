#include<bits/stdc++.h>
using namespace std;
vector<char> s;
int n;
int a;
char c;
int main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	long long l = 0;
	long long ans = 0;
	for(int i = 0; i < n; i++){
		cin >> a >> c;
		for(int j = 0;j < a; j++){
			s.push_back(c);
			l++;
		}
	}
	for(int i = 0; i < l/2; i++){
		if(s[i] != s[l-1-i]){
			s[l-1-i] = s[i];
			ans++;
		}
	}
	cout << ans;
	
	
	
	return 0;
}
/*
3
2 a
2 b
1 c
6
1000000000 a
1000000000 a 
1000000000 a 
1000000000 b 
1000000000 b 
1000000000 b
Trick||Treat!
*/

