#include <bits/stdc++.h>
using namespace std;
int main(){
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
		int k=0;
		for(int i=0;i<2;i++){
			if(s1[i]==s2[i]){
				k++;
				continue;
			}
			else{
				cout<<"000";
				return 0;
			}
		}
		if(k==2){
			cout<<"1";
			if(s1[2]=='D'||s1[2]=='F'){
				if(s2[2]=='D'||s2[2]=='F'){
					cout<<"11";
				}
			}
			else{
				if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
					if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
						cout<<"1";
						if(s1[2]=='C'&&s2[2]=='A'){
							cout<<"0";
						}
						else if(s1[2]=='A'&&s2[2]=='C'){
							cout<<"0";
						}
						else{
							cout<<"1";
						}
					}
					else{
						cout<<"00";
						return 0;
					}
			 	}
				else{
					cout<<"00";
					return 0;
				}
			}
		}
	}
	else{
		cout<<"0000";
		return 0;
	}
	return 0;
}