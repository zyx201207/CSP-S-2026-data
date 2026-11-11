#include<bits/stdc++.h>
using namespace std;
string C1,S1,C2,S2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>C1>>S1>>C2>>S2;
	if(C1!=C2){
		cout<<"0000"<<endl;
	} 
	else{
		char pos1=S1[0];
		char pos11=S1[1];
		char pos2=S2[0];
		char pos22=S2[1];
		if(pos1!=pos2 or pos11!=pos22){
			cout<<"1000"<<endl;
		} 
		else{
			if(S1[2]=='D' or S1[2]=='E'){
				if(S2[2]!='D' and S2[2]!='E'){
					cout<<"1100"<<endl;
				}
				else cout<<"1111"<<endl;
			}
			else{
				if(S2[2]=='D' or S2[2]=='E'){
					cout<<"1100"<<endl;
				}
				else {
					if((S1[2]=='A' and S2[2]=='C') or (S1[2]=='C' and S2[2]=='A')){
						cout<<"1110"<<endl;
					}
					else cout<<"1111"<<endl;
				}
			}
		}
	}
	return 0;
}
