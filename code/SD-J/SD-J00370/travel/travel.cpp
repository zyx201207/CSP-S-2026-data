#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;
int c1,c2;
char s1[5],s2[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<"1";
			if(s1[2]=='D'&&s2[2]=='F'){
				cout<<"11";
			}else if(s1[2]=='F'&&s2[2]=='D'){
				cout<<"11";
			}else if(s1[2]=='C'&&s2[2]=='D'){
				cout<<"00";
			}else if(s1[2]=='D'&&s2[2]=='C'){
				cout<<"00";
			}else{
				int t=abs(s1[2]-s2[2]);
				if(t==1){
					cout<<"11";
				}else{
					if(s1[2]=='A'&&s2[2]=='C'){
						cout<<"10";
					}else if(s1[2]=='C'&&s2[2]=='A'){
						cout<<"10";
					}else{
						cout<<"00";
					}
				}
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
} 
