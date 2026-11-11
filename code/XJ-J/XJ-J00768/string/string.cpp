#include <bits/stdc++.h>

using namespace std;


int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s,sf;
	int n;
	cin >> n;
	for(int i =1;i<=n;i++){
		int x;
		string a;
		cin >> x>>a;
		for(int j =1;j<=x;j++){
			s+=a;
		}
	}
	for(int i=s.size()-1;i>=0;i--){
		sf+=s[i];
	}
	if(sf==s){
		cout << 0;
	}
	return 0;
}