#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1;
	string c2,s2;
	string ans;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)ans+="1";
	else{
		ans+="0000";
		cout<<ans;
		return 0;
	}
	string l1=s1.substr(0,2);
	string l2=s2.substr(0,2);
	string z1=s1.substr(2,1);
	string z2=s2.substr(2,1);
	if(l1==l2){
		ans+="1";	
		
		if(z1>="D"&&z2>="D"||z1<="C"&&z2<="C")ans+="1";
		else ans+="0";
		
		if(z1=="D"&&z2=="F"||z1=="F"&&z2=="D")ans+="1";
		else if(z1=="C"&&z2=="B"||z1=="B"&&z2=="C")ans+="1";
		else if(z1=="B"&&z2=="A"||z1=="A"&&z2=="B")ans+="1";
		else ans+="0";
	}
	else{
		ans+="000";
	}

	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
