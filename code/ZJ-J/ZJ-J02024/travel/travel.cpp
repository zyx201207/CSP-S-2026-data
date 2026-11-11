#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<"1";
			if(s1[2]>'C'&&s2[2]>'C'){
				cout<<"11";
			}else{
				if(s1[2]>'C'&&s2[2]<='C'||s1[2]<='C'&&s2[2]>'C'){
					cout<<"00";
				}else{
					if(s1[2]=='B'||s2[2]=='B'){
						cout<<"11";
					}else{
						cout<<"10";
					}
				}
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
