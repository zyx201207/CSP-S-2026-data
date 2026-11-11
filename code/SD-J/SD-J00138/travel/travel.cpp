#include<bits/stdc++.h>
using namespace std;
int C1,	C2,A1,A2;
string S1,S2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>C1>>S1>>C2>>S2;
	if(C1!=C2){
		cout<<"0000";
		return 0;
	}else{
		cout<<"1";
	}
	A1=int(S1[0]-'0')*10+int(S1[1]-'0');
	A2=int(S2[0]-'0')*10+int(S2[1]-'0');
	if(A1!=A2){
		cout<<"000";
		return 0;
	}else{
		cout<<"1";
	}
	if((S1[2]<='C'&&S2[2]<='C')||(S1[2]>'C'&&S2[2]>'C')){
		cout<<"1";
	}else{
		cout<<"00";
		return 0;
	}
	if(S1[2]==S2[2]+1||S1[2]==S2[2]-1){
		cout<<"1";
	}else{
		cout<<"0";
	}
	return 0;
}
