#include<bits/stdc++.h>
using namespace std;
int f1=1,f2=1,f3=1,f4=1;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	string ss1,ss2;
	ss1+=s1[0];ss1+=s1[1];
	ss2+=s2[0];ss2+=s2[1];
	if(ss1!=ss2){
		cout<<"1000";
		return 0;
	}
	string sss1,sss2;
	sss1=s1[2];
	sss2=s2[2];
	if((sss1=="A" && sss2=="D") || (sss1=="B" && sss2=="D") || (sss1=="C" && sss2=="D") || (sss1=="A" && sss2=="F") || (sss1=="B" && sss2=="F") || (sss1=="C" && sss2=="F")){
		cout<<"1100";
		return 0;
	}
	if((sss1=="A" && sss2=="B") || (sss1=="B" && sss2=="A") || (sss1=="B" && sss2=="C") || (sss1=="C" && sss2=="B") || (sss1=="D" && sss2=="F") || (sss1=="F" && sss2=="D")){
		cout<<"1111";
		return 0;
	}
	cout<<"1110"; 
	return 0;
}
