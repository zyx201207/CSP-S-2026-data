#include<bits/stdc++.h>
using namespace std;
//unsigned operator prioeity_queue upper_bound lower_bound
string c1,s1,c2,s2;
bool f(){
	long long x,y;
	if(s1[2]=='A'){
		x=1;
	}
	if(s1[2]=='B'){
		x=2;
	}
	if(s1[2]=='C'){
		x=3;
	}
	if(s1[2]=='D'){
		x=5;
	}
	if(s1[2]=='F'){
		x=6;
	}
	if(s2[2]=='A'){
		y=1;
	}
	if(s2[2]=='B'){
		y=2;
	}
	if(s2[2]=='C'){
		y=3;
	}
	if(s2[2]=='D'){
		y=5;
	}
	if(s2[2]=='F'){
		y=6;
	}
	if(abs(x-y)==1){
		return false;
	}
	return true;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
	}
	else{
		cout<<"1";
		if(s1[0]!=s2[0]||s1[1]!=s2[1]){
			cout<<"000";
		}
		else{
			cout<<"1";
			if((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='D'||s2[2]=='F')){
				cout<<"00";
			}
			else if((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')){
				cout<<"00";
			}
			else{
				cout<<"1";
				if(f()){
					cout<<"0";
				}
				else{
					cout<<"1";
				}
			}
		}
	}
	return 0;
}
