#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> s1 >> s2 >> s3 >> s4;
	if(s1==s3) cout << 1;
	else{
		cout << 0;
	}
	string num1 = s2.substr(0,2);
	string num2 = s4.substr(0,2);
	if(num1==num2) cout << 1;
	else cout << 0;
	
	char str1 = s2[2];
	char str2 = s4[2];
	if((str1 <= 67 && str2 <= 67)||(str1 > 67 && str2 > 67)) cout << 1;
	else cout << 0;
	
	if((abs(str1-str2)<=1)&&((str1!='C'&&str2!='D')&&(str2!='C'&&str1!='D'))){
		cout << 1;
	}else{
		cout << 0;
	}
		
	return 0;
}
