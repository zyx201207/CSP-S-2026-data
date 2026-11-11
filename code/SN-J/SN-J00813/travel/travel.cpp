//SN-J00813 西安翱翔中学 唐子璇 
#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b,a1,b1;
	char a2,b2;
	cin>>a>>a1>>a2>>b>>b1>>b2;
	if(a==b){
		cout<<"1";
		if(a1==b1){
			cout<<"1";
			if(a2=='A'){
				if(b2=='B'){
					cout<<"11";
				}else if(b2=='C'){
					cout<<"10";
				}else{
					cout<<"00";
				}
			}else if(a2=='B'){
				if(b2!='E'&&b2!='F'){
					cout<<"11";
				}else{
					cout<<"00";
				}
			}else if(a2=='C'){
				if(b2=='B'){
					cout<<"11";
				}else if(b2=='A'){
					cout<<"10";
				}else{
					cout<<"00";
				}
			}else{
				cout<<"1111";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	
	return 0;
} 
