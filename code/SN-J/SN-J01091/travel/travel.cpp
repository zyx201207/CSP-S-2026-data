#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string bh1,bh2;
	int cx1=0,cx2=0;
	cin>>cx1>>bh1>>cx2>>bh2;
	if(cx1==cx2){
		cout<<"1";
		if(bh1[0]==bh2[0]&&bh1[1]==bh2[1]){
			cout<<"1";
			if((bh1[2]=='A'&&bh2[2]=='B')||(bh1[2]=='A'&&bh2[2]=='C')||(bh1[2]=='B'&&bh2[2]=='C')||(bh1[2]=='D'&&bh2[2]=='F')||(bh1[2]=='B'&&bh2[2]=='A')||(bh1[2]=='C'&&bh2[2]=='A')||(bh1[2]=='C'&&bh2[2]=='B')||(bh1[2]=='F'&&bh2[2]=='D')){
				cout<<"1";
				if((bh1[2]=='A'&&bh2[2]=='B')||(bh1[2]=='B'&&bh2[2]=='C')||(bh1[2]=='D'&&bh2[2]=='F')||(bh1[2]=='B'&&bh2[2]=='A')||(bh1[2]=='C'&&bh2[2]=='B')||(bh1[2]=='F'&&bh2[2]=='D')){
					cout<<"1";
				}
				else{
					cout<<"0";
				}
			}
			else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
} 
