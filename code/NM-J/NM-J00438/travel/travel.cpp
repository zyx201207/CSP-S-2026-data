#include<iostream>
#include<cstring>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a1;
	string a2;
	string b1;
	string b2;
	cin>>a1>>a2>>b1>>b2;
	if(a1!=b1){
		cout<<"0000";
	}else{
		cout<<'1';
		bool f=true;
		for(int i=0;i<2;i++){
			if(a2[i]!=b2[i]){
				cout<<"000";
				f=false;
			}
		} 
		if(f==true){
			cout<<'1';
			if((a2[2]=='A'&&b2[2]=='D')||
			   (a2[2]=='A'&&b2[2]=='F')||
			   (a2[2]=='B'&&b2[2]=='D')||
			   (a2[2]=='B'&&b2[2]=='F')||
			   (a2[2]=='C'&&b2[2]=='D')||
			   (a2[2]=='C'&&b2[2]=='F')||
			   (a2[2]=='D'&&b2[2]=='A')||
			   (a2[2]=='D'&&b2[2]=='B')||
			   (a2[2]=='D'&&b2[2]=='C')||
			   (a2[2]=='F'&&b2[2]=='A')||
			   (a2[2]=='F'&&b2[2]=='B')||
			   (a2[2]=='F'&&b2[2]=='C')){
			   	cout<<"00";
			}else{
				cout<<'1';
				if(a2[2]+1==b2[2]||a2[2]-1==b2[2]){
					cout<<'1';
				}else{
					cout<<'0';
				}
			}
		}
	}
	return 0;
}
