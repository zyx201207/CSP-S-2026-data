#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int r,x;
	char rz[5]={},xz[5]={};
	cin>>r;
	for(int i=0;i<3;i++){
		cin>>rz[i];
	}
	cin>>x;
	for(int i=0;i<3;i++){
		cin>>xz[i];
	}
	if(r==x){
		cout<<"1";
	}else{
		cout<<"0000";
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	if((rz[0]==xz[0]) && (rz[1]==xz[1])){
		cout<<"1";
	}else{
		cout<<"0";
	}
	bool f=0;
	if((rz[0]==xz[0]) && (rz[1]==xz[1])){
		if((rz[2]=='A' || rz[2]=='B' || rz[2]=='C') && (xz[2]=='A' || xz[2]=='B' || xz[2]=='C')){
		cout<<"1";
		f=1;
		}else if((rz[2]=='D' || rz[2]=='F') && (xz[2]=='D' || xz[2]=='F')){
		cout<<"11";
		}else{
		cout<<"00";
		}
	}else{
		cout<<"00";
	}
	if(f==1){
		if((rz[2]=='A' && xz[2]=='B') || (xz[2]=='A' && rz[2]=='B')){
			cout<<"1";
		}else if((rz[2]=='C' && xz[2]=='B') || (xz[2]=='C' && rz[2]=='B')){
			cout<<"1";
		}else{
			cout<<"0";
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
