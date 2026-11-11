#include<iostream>
using namespace std;
string s1,s2,s3,s4,s5,s6;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	s5=s2[2],s6=s4[2];
	if(s1==s3){
		cout<<1;
		if(s2[0]==s4[0]&&s2[1]==s4[1]){
			cout<<1;
			if((s5=="A"&&s6=="B")||(s5=="A"&&s6=="C")||(s5=="B"&&s6=="C")||(s5=="D"&&s6=="F")||(s5=="B"&&s6=="A")||(s5=="C"&&s6=="A")||(s5=="C"&&s6=="B")||(s5=="F"&&s6=="D")){
				cout<<1;
				if(!((s5=="A"&&s6=="C")||(s5=="C"&&s6=="A"))){
					cout<<1;
				}
				else{
					cout<<0;
				}
			}
			else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
}
