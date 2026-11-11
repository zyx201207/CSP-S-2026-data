#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int rz,xz,cnt=0,num=0,js=0;
	string rb,xb;
	cin>>rz>>rb>>xz>>xb;
	if(rz == xz){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	
	for(int i=0;i<=2;i++){
		if(rb[0] == xb[0]){
			cnt++;
			
			
		}
		if(rb[1] == xb[1]){
			cnt++;
		}
		if((char)rb[2] <=67 && (char)xb[2]<=67){
			num ++;
			if(abs((char)rb[2] -(char)xb[2]) == 1){
				js++;
			}
		}
		if((char)rb[2] =='E'&&(char)xb[2] =='F'){
			num ++;
			js++;
		}
		if((char)rb[2] == 'F'&&(char)xb[2] == 'E'){
			num ++;;
			js++;
		}
		
		
	}


	if(cnt==2){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	if(num ==1){
		cout<<"1";
		if(js==1){
			cout<<"1";
		}
	}
	else{
		cout<<"0"<<"0";
	}
	
	return 0;
}
