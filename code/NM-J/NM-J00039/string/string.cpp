#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);

	long long n;
	cin >> n;
	string str;
	for (int i=1; i<=n; i++){
		int l;char c;
		cin >> l >> c;
		for (int i=1; i<=l; i++){
			str = str + c;
		}
	}
	string s1 = str.substr(0,str.size()/2);
	string s2 = str.substr(str.size()/2+1,str.size()/2);

	reverse(s2.begin(),s2.end());

	int cnt = 0;
	for (int i=0; i<s1.size(); i++){
		if (s1[i] != s2[i]){
			cnt++;
		}
	}

	cout << cnt;


	return 0;
}
