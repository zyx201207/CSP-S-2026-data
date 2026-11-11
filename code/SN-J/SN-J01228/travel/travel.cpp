#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int a=s1[2]-'1';
	int b=s2[2]-'1';
	if(c1!="01" && c1!="16" && c2!="01" && c2!="16" && c1<="17" && c2<="17"){
		if(c1==c2){
			cout<<"1";
			if(s1[0]==s2[0] && s1[1]==s2[1]){
				cout<<"1";
				if((a<=18 && b<=18) || (a>=19 &&b>=19)){
					cout<<"1";
					if((a==17 && b==18) || (a==18 && b==17) || (a==19 && b==21) || (a==21 && b==19) || (a==16 && b==17) || (a==17 && b==16)){
						cout<<"1";
					}
					else{
						cout<<"0";
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
	}
	return 0;
}
