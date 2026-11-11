#include<bits/stdc++.h>
using namespace std;
bool b1=true,b2=true,b3=true,b4=true,by=true;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,c3,c4;
	cin>>c1>>c2>>c3>>c4;
	if(c1==c3){
		cout<<"1";
	}else{
		cout<<"0";
		b1=false;
	}
	if(b1==false){
		cout<<"0";
		b2=false;
	}else{
		for(int i=0;i<2;i++){
			if(c2[i]!=c4[i]){
				by=false;
			}
		}
		if(by==true){
			cout<<"1";
		}else{
			cout<<"0";
			b2=false;
		}
	}
	if(b2==false){
		cout<<"0";
	}else{
		if(c2[2]=='C'&&c4[2]=='D' || c2[2]=='D'&&c4[2]=='C'){
			cout<<"0";
			b3=false;
		}else if(c2[2]=='A'||c2[2]=='B'||c2[2]=='C' && c4[2]=='A'||c4[2]=='B'||c4[2]=='C'){
			cout<<"1";
			b3=true;
		}else if(c2[2]=='D'||c2[2]=='F' && c4[2]=='D'||c4[2]=='F'){
			cout<<"1";
			b3=true;
		}
	}
	if(b1==false||b3==false){
		cout<<"0";
	}else if(c2[0]==c4[0] && c2[2]==c4[2] && c2[1]==c4[1]-1||c2[1]==c4[1]+1){
		cout<<"1";
	}else if(c2[0]==c4[0] && c2[1]==c4[1] && c2[2]==c4[2]-1||c2[2]==c4[2]+1){
		cout<<"1";
	}else{
		cout<<"0";
	}
	return 0;
}
