#include <bits/stdc++.h>
using namespace std;
string seat(string c1,string s1,string c2,string s2);
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	
	cout<<seat(c1,s1,c2,s2)<<endl;
	
	return 0;
}
string seat(string c1,string s1,string c2,string s2){
	if(c1!=c2)
		return "0000";
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		char seat1,seat2;
		seat1=s1[2];
		seat2=s2[2];
		if((seat1=='A'||seat1=='B'||seat1=='C')&&(seat2=='A'||seat2=='B'||seat2=='C')){
			if(abs(seat1-seat2)==1)
				return "1111";
			else
				return "1110";
		}else if((seat1=='D'||seat1=='F')&&(seat2=='D'||seat2=='F')){
			if(abs(seat1-seat2)==1)
				return "1111";
			else
				return "1110";
		}else
			return "1100";
	}else
		return "1000";
}
