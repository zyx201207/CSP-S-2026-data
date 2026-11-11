#include<bits/stdc++.h>
using namespace std;
int main(){
	string c1,c2,s1,s2;
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1==c2)cout<< "1";
	else {
		cout << "0000";
		return 0;
	}
	string s3,s4;
	for(int i=0;i<s1.size()-1;i++){
		s3=s3+s1[i];
		s4 = s4+s2[i];
	}
	char x=s1[2],y=s2[2];
	if(s3==s4)cout << "1";
	else {
		cout << "000";
		return 0;
	}
	if((x<='C'&&x>='A'&&y<='C'&&y>='A')||(x>='D'&&x<='F'&&y>='D'&&y<='F')){
		cout << "1";
	}else{
		cout << "00";
		return 0;
	}
	if((char)x+1==y||(char)x-1==y){
		cout << "1";
	}else{
		cout << "0";
	}
	return 0;
} 
