#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1!=c2){
		cout << "0000";
		return 0;
	}
	string a=s1.substr(0,2);
	string b=s2.substr(0,2);
	if(a!=b){
		cout << "1000";
		return 0;
	}
	if(s1[2]=='D'&&s2[2]=='F'){
		cout << "1111";
	}else if(s1[2]=='F'&&s2[2]=='D'){
		cout << "1111";
	}else if(s1[2]=='D'||s2[2]=='D'||s1[2]=='F'||s2[2]=='F'){
		cout << "1100";
	}else if(abs(s1[2]-s2[2])==1){
		cout << "1111";
	}else{
		cout << "1110";
	}
	return 0;
}