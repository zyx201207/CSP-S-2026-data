#include<bits/stdc++.h>

using namespace std;

int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s,t,str,tr;
	cin>>s>>t>>str>>tr;
	if(s[0]!=str[0] or s[1]!=str[1]) {
		cout<<"0000";
		return 0;
	}
	if(t[0]!=tr[0] or t[1]!=tr[1]) {
		cout<<"1000";
		return 0;
	}
	int p=(t[2]-'A'+1),q=(tr[2]-'A'+1);
	if((p<4 and q>3) or (p>3 and q<4)) {
		cout<<"1100";
		return 0;
	}
	if(abs(p-q)>1) {
		cout<<"1110";
		return 0;
	}
	cout<<"1111";
	return 0;
} 
