#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2;
	char s1[3],s2[3];
	cin>>c1;
	for(int i=0;i<3;i++){
		cin>>s1[i];
	}
	cin>>c2;
	for(int i=0;i<3;i++){
		cin>>s2[i];
	}
	if(c1=="01"||c1=="16"||c2=="01"||c2=="16"){
		return 0;
	}
	if(c1==c2&&s1==s2){
		return 0;
	}
	if(c1==c2){
		cout<<"1";
		if(s1[0]+s1[1]==s2[0]+s2[1]){
			cout<<"1";
			if(int(s1[2])>67&&int(s2[2]>67)){
				cout<<"11";
			}
			if(int(s1[2])>67&&int(s2[2])<=67){
				cout<<"00";
				return 0;
			}
			if(int(s1[2])<=67&&int(s2[2])>67){
				cout<<"00";
				return 0;
			}
			if(int(s1[2])<=67&&int(s2[2]<=67)){
				cout<<"1";
				if(s1[2]=='A'){
					if(s2[2]=='B'){
						cout<<"1";
					}else{
						cout<<"0";
					}
				} 
				if(s1[2]=='B'){
					cout<<"1";
				}
				if(s1[2]=='C'){
					if(s2[2]=='B'){
						cout<<"1";
					}else{
						cout<<"0";
					}
				}
			}else{
				cout<<"0";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	
	return 0;
} 
