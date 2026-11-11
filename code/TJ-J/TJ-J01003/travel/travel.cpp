#include<bits/stdc++.h>
using namespace std;
string c,s,cc,ss;
int main(){
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>s>>cc>>ss;
	if(c==cc){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	string rs=s.substr(0,2);
	string xs=ss.substr(0,2);
	if(rs==xs){
		cout<<"1";
	}else{
		cout<<"000";
		return 0;
	}
	string zs=s.substr(2,3);
	string zss=ss.substr(2,3);
	if(zs=="D"&&zss=="F"||zss=="D"&&zs=="F"||zs>="A"&&zs<="C"&&zss>="A"&&zss<="C"){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(zs=="A"&&zss=="B"||zs=="B"&&zss=="C"||zs=="D"&&zss=="F"||zs=="B"&&zss=="A"||zs=="C"&&zss=="B"||zs=="F"&&zss=="D"){
		cout<<"1";
	}else{
		cout<<"0";
	}
	return 0;
} 
