#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	string s1,s2,x1,x2;
	cin>>s1>>s2>>x1>>x2;
	if(s1==x1){
		cout<<"1";
	}
	else{
		cout<<"0000"<<endl;
		return 0;
	}
	if(s2[0]==x2[0] && s2[1]==x2[1]){
		cout<<"1";
	}
	else{
		cout<<"000";
		return 0;
	}
	if((s2[2]=='A' && x2[2]=='B') || (x2[2]=='A' && s2[2]=='B') || (s2[2]=='B' && x2[2]=='C') || (x2[2]=='B' && s2[2]=='C') || (s2[2]=='D' && x2[2]=='E') || (x2[2]=='D' && s2[2]=='E')){
		cout<<"11";
	}
	else if((s2[2]=='C' && x2[2]=='D') || (x2[2]=='C' && s2[2]=='D') || (s2[2]=='C' && x2[2]=='E') || (x2[2]=='C' && s2[2]=='E') || (s2[2]=='B' && x2[2]=='D') || (x2[2]=='B' && s2[2]=='D') || (s2[2]=='A' && x2[2]=='D') || (x2[2]=='A' && s2[2]=='D') || (s2[2]=='B' && x2[2]=='E') || (x2[2]=='B' && s2[2]=='E') || (s2[2]=='A' && x2[2]=='E') || (x2[2]=='A' && s2[2]=='E')){
		cout<<"00";
	}
	else{
		cout<<"10";
	}
	return 0;
}
