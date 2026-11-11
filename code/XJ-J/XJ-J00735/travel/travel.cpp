#include<bits/stdc++.h>
using namespace std;
bool a,b,c,d;
string c1,c2,s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) a=1;
	else{
		cout<<"0000";
		return 0;
	}
	
	if(s1[1]==s2[1] && s1[0]==s2[0]) b=1;
	else{
		cout<<a;
		cout<<"000";
		return 0;
	}
	
	if(s1[2]=='D' || s2[2]=='D' || s1[2]=='F' || s2[2]=='F'){
		if(s1[2]=='D' || s1[2]=='F'){
			if(s2[2]=='D' || s2[2]=='F') c=1;
		}else c=0;
	}else c=1;
	
	if(c){
		if(s1[2]-s2[2]==1 || s2[2]-s1[2]==1) d=1;
	}else d=0;
	
	cout<<a<<b<<c<<d;
	return 0;
}