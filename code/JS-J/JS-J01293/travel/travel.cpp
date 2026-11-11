#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,pai1,pai2;
char guodao1,guodao2;
long long weizhi1,weizhi2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	else{
		cout<<"1";
		pai1=s1[0]+s1[1];
		pai2=s2[0]+s2[1];
		if(pai1!=pai2){
			cout<<"000";
			return 0;
		}
		else{
			cout<<"1";
			guodao1=s1[2];
			guodao2=s2[2];
			if(guodao1=='A'||guodao1=='B'||guodao1=='C'){
				weizhi1=1;
			}
			else if(guodao1=='D'||guodao1=='F'){
				weizhi1=2;
			}
			if(guodao2=='A'||guodao2=='B'||guodao2=='C'){
				weizhi2=1;
			}
			else if(guodao2=='D'||guodao2=='F'){
				weizhi2=2;
			}
			if(weizhi1!=weizhi2){
				cout<<"00";
				return 0;
			}
			else{
				cout<<"1";
				if(guodao1=='A'){
					if(guodao2=='B'){
						cout<<"1";
						return 0;
					}
				}
				if(guodao1=='B'){
					if(guodao2=='A'||guodao2=='C'){
						cout<<"1";
						return 0;
					}
				}
				if(guodao1=='C'){
					if(guodao2=='B'){
						cout<<"1";
						return 0;
					}
				}
				if(guodao1=='D'){
					if(guodao2=='F'){
						cout<<"1";
						return 0;
					}
				}
				if(guodao1=='F'){
					if(guodao2=='D'){
						cout<<"1";
						return 0;
					}
				}
				else{
					cout<<"0";
					return 0;
				}
			}
		}
	}
	return 0;
}
