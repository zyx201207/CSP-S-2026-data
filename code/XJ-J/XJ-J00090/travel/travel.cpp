#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool iscsame(string c1,string c2){
	if(c1==c2){
		return true; 
	}
	else{
		return false;
	}
}
bool islsame(string s1,string s2){
	if((s1[0]+s1[1]==s2[0]+s2[1])&&(s1!=s2)){
		return true;
	}
	else{
		return false;
	}
}
bool ismsame(string s1,string s2){
	if(islsame(s1,s2)&&((s1[2]<='C'*1&&s2[2]<='C'*1)||(s1[2]>='D'*1&&s2[2]>='D'*1))){
		return true;
	}
	else{
		return false;
	}
}
bool sidesame(string s1,string s2){
	if((s1[2]*1+1==s2[2]*1||s1[2]*1-1==s2[2]*1)&&islsame(s1,s2)&&ismsame(s1,s2)){
		return true;
	}
	else{
		return false;
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >>c1 >>s1 >> c2 >>s2;
	if(iscsame(c1,c2))cout << "1";
	else cout << "0";
	if(islsame(s1,s2))cout << "1";
	else cout << "0";
	if(ismsame(s1,s2))cout <<"1" ;
	else cout << "0";
	if(sidesame(s1,s2))cout <<"1";
	else cout <<"0";
	return 0;
}
