//SN-J01294
#include<bits/stdc++.h>
using namespace std;
string C1,S1,C2,S2;
int s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>C1>>S1>>C2>>S2;
	if(S1[0]=='0'){
		s1=S1[1]-'0';
	}else{
		s1=10+S1[1]-'0';
	}
	if(S2[0]=='0'){
		s2=S2[1]-'0';
	}else{
		s2=10+S2[1]-'0';
	}
	if(C1==C2){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	if(s1==s2){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	if((S1[2]-'A'<=2 && S2[2]-'A'<=2) || (S1[2]-'A'>=3 && S2[2]-'A'>=3)){
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}
	if(abs((S1[2]-'A')-(S2[2]-'A'))==1){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
