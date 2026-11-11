#include <bits/stdc++.h>
using namespace std;
int c1,c2,num1,num2;
bool sid1,sid2;
char s1[10],s2[10];
bool pd(char x){
	return x<='C';
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c1>>s1+1>>c2>>s2+1;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	else{
		num1=(s1[1]-48)*10+s1[2]-48;
		num2=(s2[1]-48)*10+s2[2]-48;
		if(num1!=num2) cout<<"1000";
		else{
			sid1=pd(s1[3]);sid2=pd(s2[3]);
			if(sid1!=sid2) cout<<"1100";
			else{
				if(sid1&&(s1[3]=='A'&&s2[3]=='C'||s1[3]=='C'&&s2[3]=='A')) cout<<"1110";
				else cout<<"1111"; 
			}
		}
	}
	return 0;
}
