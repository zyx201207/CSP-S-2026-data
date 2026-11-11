#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	string c1, s1, c2, s2;
	cin>>c1>>s1>>c2>>s2;
	//Q1
	if(c1==c2){
		cout<<"1";
	}
	else{
		cout<<"0000";
		return 0;
	}
	//Q2 
	if(s1[1]==s2[1] && s1[0]==s2[0]){
		cout<<"1";
	}else{
		cout<<"000";
		return 0;
	}
	//Q3
	char a=s1[2], b=s2[2];
	if(a<='C' && b<='C' || a>'C' && b>'C'){
		cout<<"1";
	}else{
		cout<<"00";
		return 0;
	}
	//Q4
	if(abs((int)a-(int)b)==1){
		cout<<"1";
	}else{
		cout<<"0";
	}
	return 0;
} 
