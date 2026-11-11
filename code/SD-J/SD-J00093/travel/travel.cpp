#include<bits/stdc++.h>
using namespace std;
string A_pl,B_pl;
int A_car,B_car;
bool check(string s){
	if((s[2]=='D')||(s[2]=='F')){
		return true;
	}else return false;
}
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>A_car>>A_pl; 
	cin>>B_car>>B_pl; 
	if(A_car!=B_car){
		cout<<"0000";
		return 0;
	}
	if((A_pl[0]!=B_pl[0])||(A_pl[1]!=B_pl[1])){
		cout<<"1000";
		return 0;
	}
	if(check(A_pl)^check(B_pl)){
		cout<<"1100";
		return 0;
	}
	if(A_pl>B_pl)swap(A_pl,B_pl);
	if(B_pl[2]=='F'){
		cout<<"1111";
		return 0;
	}
	if((B_pl[2]-A_pl[2])==1){
		cout<<"1111";
	}else{
		cout<<"1110";
	}
	return 0; 
}
