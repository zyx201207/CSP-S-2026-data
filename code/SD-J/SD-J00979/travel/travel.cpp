#include<bits/stdc++.h>
using namespace std;
int ca,cb;
char sa[3],sb[3];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>ca;
	for(int i=1;i<4;i++){
		cin>>sa[i];
	}
	cin>>cb;
	for(int i=1;i<4;i++){
		cin>>sb[i];
	}
	if(ca==cb){
		if(sa[2]==sb[2]&&sa[1]==sb[1]) {
			if((sa[3]%100=='A'||sa[3]%100=='B'||sa[3]%100=='C')&&(sb[3]%100=='A'||sb[3]%100=='B'||sb[3]%100=='C')){
				if((sa[3]%100=='A'&&(sb[3]%100=='B'))||(sa[3]%100=='B'&&(sb[3]%100=='A'||sb[3]%100=='C'))||(sa[3]%100=='C'&&(sb[3]%100=='B'))){
					cout<<"1111";
				}else{
					cout<<"1110";
				}
			}else if((sa[3]%100=='D'||sa[3]%100=='F')&&(sb[3]%100=='D'||sb[3]%100=='F')){
				if ((sa[3]%100=='D'&&(sb[3]%100=='F'))||(sa[3]%100=='F'&&(sb[3]%100=='D'))){
					cout<<"1111";
				}else{
					cout<<"1110";
				}
			}else{
				cout<<"1100";
			}
		}else{
			cout<<"1000";
		}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     
	}else{
		cout<<"0000";
	}
	return 0;
} 
