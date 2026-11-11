#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2,s;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		if(s1.substr(0,2)==s2.substr(0,2)){
			s="11";
		}
		else{
			s="1000";
			cout<<s;
			return 0;
		}
	}
	else{
		s="0000";
		cout<<s;
		return 0;
	}
	if(s1.substr(2,3)=="D"||s1.substr(2,3)=="F"){
		if(s2.substr(2,3)=="D"||s2.substr(2,3)=="F"){
			s="1111";
		    cout<<s;
		    return 0;
		}
		else{
			s="1100";
		    cout<<s;
		    return 0;
		}
	}
	else if(s2.substr(2,3)=="D"||s2.substr(2,3)=="F"){
		s="1100";
		cout<<s;
		return 0;
	}
	else if(s1.substr(2,3)=="B"||s2.substr(2,3)=="B"){
		s="1111";
		cout<<s;
		return 0;
	}
	else{
		s="1110";
		cout<<s;
		return 0;
	}
	return 0;
}
