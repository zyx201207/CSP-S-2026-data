#include<bits/stdc++.h>
using namespace std;
string C1,S1,C2,S2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>C1>>S1>>C2>>S2;
	if(C1!=C2){
		cout<<"0000";
		return 0;
	}else{
		cout<<"1";
		if((S1[0]!=S2[0])||(S1[1]!=S2[1])){
			cout<<"000";
			return 0;
		}else{
			cout<<"1";
			if(S1[2]=='D' || S1[2]=='F'){
				if(S2[2]=='D' || S2[2]=='F'){
					cout<<"11";
					return 0;
				}else{
					cout<<"00";
					return 0;
				}
			}else{
				if(S2[2]=='D' || S2[2]=='F'){
					cout<<"00";
					return 0;
				}else{
					cout<<"1";
					if((S1[2]=='A'&&S2[2]=='C')||(S1[2]=='C'&&S2[2]=='A')){
						cout<<"0";
						return 0;
					}else{
						cout<<"1";
						return 0;
					}
				}
			}
		}
	}
	return 0;
}
