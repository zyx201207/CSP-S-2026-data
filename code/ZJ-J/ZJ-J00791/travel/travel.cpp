#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	c1 = ' '+c1;
	c2 = ' '+c2;
	s1 = ' '+s1;
	s2 = ' '+s2;
	if(c1 != c2){
		cout<<"0000";
		return 0;
	}
	if(s1[1] != s2[1]||s1[2] != s2[2]){
		cout<<"1000";
		return 0;
	}
	if(s1[3]<='C'&&s2[3]>'C'||s1[3]>'C'&&s2[3]<='C'){
		cout<<"1100";
		return 0;
	}
	if(abs(s1[3]-s2[3]) != 1){
		cout<<"1110";
		return 0;
	}
	cout<<"1111";
	return 0;
}