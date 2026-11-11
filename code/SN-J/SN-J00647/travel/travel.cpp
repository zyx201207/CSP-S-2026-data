//吴雨桐 西安市第六中学 SN-J00647 
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	if(s1[0] != s2[0] || s1[1] != s2[1]){
		cout<<"1000";
		return 0;
	}
	char u1 = s1[2],u2 = s2[2];
	int fx1,fx2;
	if(u1 == 'A' || u1 == 'B' || u1 == 'C'){
		fx1 = 1;
	}
	else{
		fx1 = 2;
	}
	if(u2=='A' || u2=='B' || u2 == 'C'){
		fx2=1;
	}
	else{
		fx2=2;
	}
	if(fx1 != fx2){
		cout<<"1100";
		return 0;
	}
	if(u1=='A' && u2!='B'){
		cout<<"1110";
		return 0;
	}
	else if(u1=='B' && u2!='C' && u2!='A'){
		cout<<"1110";
		return 0;
	}
	else if(u1=='C' && u2!='B'){
		cout<<"1110";
		return 0;
	}
	else if(u1=='D' && u2!='F'){
		cout<<"1110";
		return 0;
	}
	else if(u1=='F' && u2!='D'){
		cout<<"1110";
		return 0;
	}
	cout<<"1111";
	return 0;
}
