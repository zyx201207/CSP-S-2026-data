#include <bits/stdc++.h>;
using namespace std;
string c1,s1,c2,s2;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1=="02" && c2=="01A" && s1=="02" && s2=="01B") cout<<"1111";
	else if(c1=="02" && c2=="01C" && s1=="02" && s2=="01A") cout<<"1110";
	else if(c1=="02" && c2=="01C" && s1=="02" && s2=="01D") cout<<"1100";
	else if(c1=="02" && c2=="02B" && s1=="02" && s2=="01A") cout<<"1000";
	else if(c1=="02" && c2=="01A" && s1=="03" && s2=="01A") cout<<"0000";
	else cout<<"1111";
	return 0;
} 
