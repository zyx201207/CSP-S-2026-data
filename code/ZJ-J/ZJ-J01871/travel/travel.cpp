#include<bits/stdc++.h>
using namespace std;
bool f1,f2,f3,f4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)f1=true;
	if(f1&&(s1[0]==s2[0]&&s1[1]==s2[1]))f2=true;
	if(f1&&f2){
		if(s1[2]=='A'){
			if(s2[2]=='B'||s2[2]=='C')f3=true;
		}
		if(s1[2]=='B'){
			if(s2[2]=='A'||s2[2]=='C')f3=true;
		}
		if(s1[2]=='C'){
			if(s2[2]=='A'||s2[2]=='B')f3=true;
		}
		if(s1[2]=='D'){
			if(s2[2]=='F')f3=true;
		}
		if(s1[2]=='F'){
			if(s2[2]=='D')f3=true;
		}
	}
	if(f1&&f2&&f3){
		if(s1[2]=='A'){
			if(s2[2]=='B')f4=true;
		}
		if(s1[2]=='B'){
			if(s2[2]=='A'||s2[2]=='C')f4=true;
		}
		if(s1[2]=='C'){
			if(s2[2]=='B')f4=true;
		}
		if(s1[2]=='D'){
			if(s2[2]=='F')f4=true;
		}
		if(s1[2]=='F'){
			if(s2[2]=='D')f4=true;
		}
	}
	cout<<f1<<f2<<f3<<f4;
	
	return 0;
}
