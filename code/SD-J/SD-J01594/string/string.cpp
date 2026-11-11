#include<bits/stdc++.h>
using namespace std;
string s,s1;
long long n,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(long long i = 1; i<=n; i++){
		long long a;
		char c;
		cin >> a;
		cin >> c;
		for(long long j = 0; j<a; j++){
			s += c;
		}
	}
	for(long long i = s.size()-1; i>=0; i--){
		s1 += s[i];
	}
	for(long long i = 0; i<s.size()/2; i++){
		if(s[i]!=s1[i]){
			ans++;
		}
	} 
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
