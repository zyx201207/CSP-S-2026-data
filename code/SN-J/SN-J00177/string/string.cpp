#include <bits/stdc++.h>
using namespace std;
char c[200005];
long long n , a[200005] , ans = 0;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 0; i < n; i ++){
		cin >> a[i] >> c[i];
		for(int j = 0; j < a[i]; j ++){
			s += c[i];
		}
	}
	for(int i = 0 , j = s.size()-1; i<s.size()/2; i ++ , j --){
		
		if(s[i] != s[j]){
			ans ++;
		}
		
	}
	cout << ans;
	//9:18Ð´Íê 
	return 0;
} 
