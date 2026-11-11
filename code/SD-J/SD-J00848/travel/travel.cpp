#include<bits/stdc++.h>
using namespace std;
string sw,sp,ew,ep;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>sw>>sp>>ew>>ep;
	if(sw==ew){
		cout<<'1';
	}
	else{
		cout<<"0000";
		return 0;
	}
	if(sp[0]==ep[0]&&sp[1]==ep[1]){
		cout<<'1';
	}
	else{
		cout<<"000";
		return 0;
	}
	if(sp[2]=='F'&&ep[2]=='D'||sp[2]=='D'&&ep[2]=='F'){
		cout<<"11";
		return 0;
	}
	else if(sp[2]=='A'&&ep[2]=='B'||sp[2]=='B'&&ep[2]=='A'){
		cout<<"11";
		return 0;
	}
	else if(sp[2]=='C'&&ep[2]=='B'||sp[2]=='B'&&ep[2]=='C'){
		cout<<"11";
		return 0;
	}
	else if(sp[2]=='C'&&ep[2]=='A'||sp[2]=='A'&&ep[2]=='C'){
		cout<<"10";
		return 0;
	}
	else{
		cout<<"00";
	}
	return 0;
}
