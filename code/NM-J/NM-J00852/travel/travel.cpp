#include<bits/stdc++.h>
using namespace std;
string C2[5];
string S2[5];
int main(){
        freopen("travel.in","r",stdin)
        freopen("travel.out","w",stdout);
	char C1,S1;
	cin>>C1;
	for(int i=1;i<=2;i++){
		cin>>C2[i];
	}
	cin>>S1;
	for(int i=1;i<=2;i++){
		cin>>S2[i];
	}
	if(C1==S1){
		cout<<"1";
		if(C2[0]==S2[0]&&C2[1]==S2[1]){
			cout<<"1";
		       
		}else{
			cout<<"0";
		}
	}else{
		cout<<"0";
	}
	return 0;
} 

