#include<bits/stdc++.h>
#define int long long
using namespace std;
string C1,S1,C2,S2;
bool check(){
	//tong ce
	if(S1[2]=='A'){
		if(S2[2]=='B' || S2[2]=='C')return true;
	}else if(S1[2]=='B'){
		if(S2[2]=='A' || S2[2]=='C')return true;
	}else if(S1[2]=='C'){
		if(S2[2]=='B' || S2[2]=='A')return true;
	}else if(S1[2]=='D'){
		if(S2[2]=='F')return true;
	}else if(S1[2]=='F'){
		if(S2[2]=='D')return true;
	}
	return false;
}
bool check1(){
	//xiangling
	if(S1[2]=='A'){
		if(S2[2]=='B')return true;
	}else if(S1[2]=='B'){
		if(S2[2]=='A' || S2[2]=='C')return true;
	}else if(S1[2]=='C'){
		if(S2[2]=='B')return true;
	}else if(S1[2]=='D'){
		if(S2[2]=='F')return true;
	}else if(S1[2]=='F'){
		if(S2[2]=='D')return true;
	}
	return false;
}
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>C1>>S1>>C2>>S2;
	if(C1==C2){
		cout<<'1';
		if(S1[0]==S2[0] && S1[1]==S2[1]){
			cout<<'1';
			if(check()){
				cout<<'1';
				if(check1()){
					cout<<'1';
				}else{
					cout<<'0';
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
