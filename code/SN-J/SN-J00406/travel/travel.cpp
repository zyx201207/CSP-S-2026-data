#include<bits/stdc++.h>
using namespace std;
int main ()  {
	char c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	long long d = s1[3] - 40,f = s2[3] - 40;
	cout<<'C' - 40<<'D' - 40;
	if(c1 == c2){
		cout<<"1";
	}
	else{
		cout<<"0000";
		return 0;
	}
	if(s1[1] == s2[1] && s1[2] == s2[2]){
		cout<<"1";
	}
	else{
		cout<<"000";
		return 0;
	}
	if((d > 27.5 && f > 27.5) || (d < 27.5 && f < 27.5)){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	if(c1 == c2 && s1[1] == s2[2] && s1[0] == s1[0] && s1[1] == s2[1] && (s1[2] == 'F' && s2[2] == 'D') || (s1[2] == 'C' && s2[2] == 'B') || (s1[2] == 'A' && s2[2] == 'B') || (s1[2] == 'D' && s2[2] == 'F') || (s1[2] == 'F' && s2[2] == 'C') || (s1[2] == 'B' && s2[2] == 'A')) {
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}
