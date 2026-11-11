#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
string a1,b1,a2,b2;
int x1,x2,z1,z2,s[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>b1>>a2>>b2;
	if(a1==a2){
		s[1]=1;
	}else{
		for(int i=1;i<=4;i++) {
			s[i]=0;
			cout<<s[i];
		}
		return 0;
	}
	x1=(b1[0]-'0')*10+(b1[1]-'0');
	x2=(b2[0]-'0')*10+(b2[1]-'0');
	if(x1==x2){
		s[2]=1;
	}else{
		for(int i=1;i<=4;i++){
			cout<<s[i];
		}
		return 0;
	}
	if(b1[2]=='A'){
		z1=1;
	}else if(b1[2]=='B'){
		z1=2;
	}else if(b1[2]=='C'){
		z1=3;
	}else if(b1[2]=='D'){
		z1=4;
	}else if(b1[2]=='F'){
		z1=5;
	}
	if(b2[2]=='A'){
		z2=1;
	}else if(b2[2]=='B'){
		z2=2;
	}else if(b2[2]=='C'){
		z2=3;
	}else if(b2[2]=='D'){
		z2=4;
	}else if(b2[2]=='F'){
		z2=5;
	}
	if(max(z1,z2)==4||(max(z1,z2)==5&&min(z1,z2)!=4)){
		for(int i=1;i<=4;i++){
			cout<<s[i];
		}
		return 0;
	}else{
		s[3]=1;
	}
	if(abs(z1-z2)==1){
		s[4]=1;
	}
	for(int i=1;i<=4;i++){
		cout<<s[i];
	}
	return 0;
}
