#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if (c1==c2){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	string s1_1,s1_2,s2_1,s2_2;
	s1_1=s1[0]+s1[1];
	s1_2=s1[2];
	s2_1=s2[0]+s2[1];
	s2_2=s2[2];
	if (s1_1==s2_1){
		cout<<"1";
	}else{
		cout<<"000";
		return 0;
	}
	if ((s1_2=="D" and s2_2=="F")  or (s1_2=="F" and s2_2=="D") or (s1_2=="A" and s2_2=="B") or (s1_2=="B" and s2_2=="C") or (s1_2=="B" and s2_2=="A") or (s1_2=="C" and s2_2=="B") or (s1_2=="A" and s2_2=="C") or (s1_2=="C" and s2_2=="A")){
		cout<<"1";		
	}else{
		cout<<"00";
		return 0;
	}
	if ((s1_2=="A" and s2_2=="B") or (s1_2=="B" and s2_2=="A") or (s1_2=="B" and s2_2=="C") or (s1_2=="C" and s2_2=="B") or (s1_2=="D" and s2_2=="F") or (s1_2=="F" and s2_2=="D")){
		cout<<"1";
		return 0;
	}else{
		cout<<"0";
		return 0;
	}
}