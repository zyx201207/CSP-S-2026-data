#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int a;
	char b;
	int n,c=0;
	string s;
	cin >> n;
	for(int i=1; i<=n; i++){
		cin >> a >> b;
		for(int j=1; j<=a; j++){
			s+=b;
		}
	}
	for(int i=0; i<=s.size()/2; i++){
		if(s[i]!=s[s.size()-i-1]) c++;
	}
	cout << c;
	return 0;
} 
