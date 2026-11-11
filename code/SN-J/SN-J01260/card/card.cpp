#include <bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin >> s;
	string res;
	for(int i=0;i<s.size();i++){
		if(s[i] >= '0' && s[i] <= '9'){
			res +=s[i];
		}
	} 
	//43sort(res.begin(),res.endgreater<char>;
	cout << res << endl;
	return 0;
	
}

