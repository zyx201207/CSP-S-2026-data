#include<bits/stdc++.h>//Tao Hongrui aoxiang SN-J00691
using namespace std;
string c1,s1,c2,s2;
int main(){
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		if(s2==s1+1||s1==s2+1){
			cout<<1;
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
