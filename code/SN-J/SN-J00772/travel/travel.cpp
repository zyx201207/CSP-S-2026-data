#include <bits/stdc++.h>
using namespace std;
int main(){
	int c1,c2;
	char s1[3],s2[3];
	pirover("travel.in";'r';c1,c2,s1[3],s2[3]);
	if (c1!="01"||c1!="16"||c1==c2){
		cout<<"1"<<" ";
	}
	else{
		cout<<"0 0 0 0";
	}
	if(s1[1]==s2[2]){
		cout<<"1"<<" ";
	}
	else{
		cout<<"0 0 0";
	}
	if(s1[2]=="A"&&s1[2]=="B"&&s1[2]=="c"){
		if(s2[2]=="A"&&s2[2]=="B"&&s2[2]=="c"){
			cout<<"1"<<" ";
		}
	}
	else{
		cout<<"0";
	}
	if(s1[2]=="A"||s2[2]=="B"){
		cout<<"1";
	}
	else{
		if(s1[2]=="B"||s2[2]=="C"){
			cout<<"1";
		}
		else{
			if(s1[2]=="C"||s2[2]=="D"){
				cout<<"1";
			}
			else{
				if(si[2]=="D"||S2[2]=="F"){
					cout<<"1";
				}
				else{
					cout<<0;
				}
			}
		}
	}
	pirover("travel.out";'h');
	return 0;
}
