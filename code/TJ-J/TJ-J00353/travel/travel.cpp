#include<bits/stdc++.h> 
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int cx1,cx2;
	string hl1,hl2;
	cin>>cx1>>hl1>>cx2>>hl2;
	if(cx1==cx2){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	for(int i=0;i<3;i++){
		if(i==0){
			if((hl1[i]==hl2[i])&&(hl1[i+1]==hl2[i+1])){
				cout<<"1";}
			else{
				cout<<"0";
			}
		}
		if(i==2){
			if(hl1[i]-'C'>0&&hl2[i]-'C'>0){
				cout<<"11";
				return 0;
			}else if(hl1[i]=='A'&&hl2[i]=='B'){
				cout<<"11";
			}else if(hl1[i]=='B'&&(hl2[i]=='A'||hl2[i]=='C')){
				cout<<"11";
			}else if(hl1[i]=='C'&&hl2[i]=='B'){
				cout<<"11";
			}else{
			cout<< "00";}
		}		
	}
	return 0;
}
