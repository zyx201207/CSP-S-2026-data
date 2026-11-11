#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	int c1,c2;
	string s1,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	int num1,num2;
	num1=(s1[0] - '0') * 10 + s1[1] - '0';
	num2=(s2[0] - '0') * 10 + s2[1] - '0';
	if(c1 == c2){
		if(num1 == num2){
			if((s1[2] <= 'C' && s2[2] <= 'C') || (s1[2] >= 'D' && s2[2] >= 'D')){
				if(s1[2] + 1 == s2[2] || s2[2] + 1 == s1[2]){
					cout << 1111;
				}
				else cout << 1110;
			}
			else cout << 1100;
		}
		else cout << 1000;
	}
	else cout << "0000";
	return 0;
}
