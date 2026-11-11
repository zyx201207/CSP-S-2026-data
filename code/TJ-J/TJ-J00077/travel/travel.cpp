#include<bits/stdc++.h>
using namespace std;
bool paihao(char a){
	if(a=='A' || a=='B' || a=='C')return 0;
	return 1;
}
int jihao(char a){
	if(a=='A' || a=='D'){
		return 0;
	}if(a=='B' || a=='F'){
		return 1;
	}
	return 2;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s_0="",s_1="",c_0="",c_1="";
	cin>>s_0>>s_1>>c_0>>c_1;
	if(s_0==c_0){
		cout<<1; 
		if(s_1[0]==c_1[0] && s_1[1]==c_1[1]){
			cout<<1;
			if(paihao(c_1[2])==paihao(s_1[2])){
				cout<<1;
				if(abs(jihao(c_1[2])-jihao(s_1[2]))==1){
					cout<<1;
				}else{
					cout<<0;
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
