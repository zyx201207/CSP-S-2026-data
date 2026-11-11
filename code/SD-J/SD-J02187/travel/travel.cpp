#include<bits/stdc++.h>
using namespace std;
int a,b;
char a1[3],b1[3];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a;

	for(int i=0;i<3;i++){
		cin>>a1[i];
	}cin>>b;
	for(int i=0;i<3;i++){
		cin>>b1[i];
	}if(a==b){
		cout<<"1";
		
			if(a1[0]==b1[0]&&a1[1]==b1[1]){

				cout<<"1";
				if(a1[2]<='C'&&b1[2]<='C'){
					cout<<"1";
				if(a1[2]+1==b1[2]||a1[2]-1==b1[2]||a1[2]=='D'&&b1[2]=='F'||a1[2]=='F'&&b1[2]=='D'){
					cout<<"1";
				}else{
					cout<<"0";
				}
				
				}else{

				cout<<"00";
			}
			
		
	
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
} 
