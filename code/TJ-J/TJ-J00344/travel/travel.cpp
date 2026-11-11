#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	string ans = "";
	if (c1 == c2){
		ans+="1";
	}else{
		cout << "0000";
		return 0;
	}
	string x,y;
	x+=s1[0];
	x+=s1[1];
	y+=s2[0];
	y+=s2[1];
	char w = s1[2],z = s2[2];
	if (x == y){
		ans += "1";
	}else {
		cout << ans << "000";
		return 0;
	}
	if (w-z==1||z-w==1){
		ans+="1";
	}else {
		cout <<ans <<"00";
		return 0;
	}
	
	if ((z<='C' && w <= 'C') || (z >= 'D'&&w>='D')){
		ans += "1";
	}else {
		cout <<ans << "0";
		return 0;
	}
	return 0;
} 
