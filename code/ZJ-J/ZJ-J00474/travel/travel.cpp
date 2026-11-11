#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char s1[5],c1[5],s2[5],c2[5];
	for(int i=1;i<=2;i++){
		cin >> s1[i];
	}
	for(int i=1;i<=3;i++){
		cin >> c1[i];
	}
	for(int i=1;i<=2;i++){
		cin >> s2[i];
		if(s2[i]!=s1[i]){
			cout << "0000";
			return 0;
		}
	}
	for(int i=1;i<=3;i++){
		cin >> c2[i];
	}
	if(c1[1]!=c2[1]||c1[2]!=c2[2]){
		cout << "1000";
		return 0;
	}
	if(c1[3]<='C'&&c2[3]>'C'){
		cout << "1100";
		return 0;
	}
	if(c1[3]>'C'&&c2[3]<='C'){
		cout << "1100";
		return 0;
	}
	if(c1[3]=='A'&&c2[3]!='B'){
		cout << "1110";
		return 0;
	}
	if(c1[3]=='B'&&(c2[3]!='A'&&c2[3]!='C')){
		cout << "1110";
		return 0;
	}
	if(c1[3]=='C'&&c2[3]!='B'){
		cout << "1110";
		return 0;
	}
	if(c1[3]=='D'&&c2[3]!='F'){
		cout << "1110";
		return 0;
	}
	if(c1[3]=='F'&&c2[3]!='D'){
		cout << "1110";
		return 0;
	}
	cout << "1111";
	return 0;
}
