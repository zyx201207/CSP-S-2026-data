#include<bits/stdc++.h>

using namespace std;

string c1,c2,s1,s2;

signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)cout<<1;
	else {
		cout<<"0000";
		return 0;
	}
	string p1=s1.substr(0,2),p2=s2.substr(0,2);
	//cout<<'\n'<<p1<<' '<<p2;
	if(p1==p2)cout<<1;
	else {
		cout<<"000";
		return 0;
	}
	char z1=s1[s1.size()-1],z2=s2[s2.size()-1];
	if(z1<='C'){
		if(z2<='C')cout<<1;
		else cout<<0;
	}
	else{
		if(z2>='D')cout<<1;
		else cout<<0;
	}
	if(z1=='A'&&z2=='B'||z1=='B'&&z2=='A'||z1=='B'&&z2=='C'||z1=='C'&&z2=='B'||z1=='D'&&z2=='F'||z1=='F'&&z2=='D')cout<<1;
	else cout<<0;
	return 0;
} 
