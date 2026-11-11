#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int ns1,ns2;
	char nc3=s1[2],ns3=s2[2];
	ns1=int(s1[0])*10+s1[1];
	ns2=int(s2[0])*10+s2[1];
	if(c1==c2){
		cout<<1;
	}else{
		cout<<0;
	}
	
	if(c1==c2&&ns1==ns2){
		cout<<1;
	}else{
		cout<<0;
	}
	
	if(c1==c2&&ns1==ns2&&((nc3=='A'&&ns3=='B')||(nc3=='A'&&ns3=='C')||(nc3=='B'&&ns3=='A')||(nc3=='B'&&ns3=='C')||(nc3=='C'&&ns3=='A')||(nc3=='C'&&ns3=='B')||(nc3=='D'&&ns3=='F')||(nc3=='F'&&ns3=='D'))){
		cout<<1;
	}else{
		cout<<0;
	}
	
	if(c1==c2&&ns1==ns2&&((nc3=='A'&&ns3=='B')||(nc3=='B'&&ns3=='A')||(nc3=='B'&&ns3=='C')||(nc3=='C'&&ns3=='B')||(nc3=='D'&&ns3=='F')||(nc3=='F'&&ns3=='D'))){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
