#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	string s1num=s1,s2num=s2;
	s1num.erase(2,1);
	s2num.erase(2,1);
	s1.erase(0,2);
	s2.erase(0,2);
	string ans="";
	bool f=1;
	if(c1==c2){
		ans+='1'; 
	}else{
		ans+='0';
		f=0;
	}
	if(f&&s1num==s2num){
		ans+='1';
	}else{
		ans+='0';
		f=0;
	}
	if(f&&((s1[0]>='A'&&s1[0]<='C'&&s2[0]>='A'&&s2[0]<='C')||(s1[0]>='D'&&s1[0]<='F'&&s2[0]>='D'&&s2[0]<='F'))){
		ans+='1';
	}
	else{
		ans+='0';
		f=0;
	}
	if(f&&abs(s1[0]-s2[0])==1){
		ans+='1';
	}else{
		ans+='0';
	}
	cout<<ans;
	return 0;
} 
