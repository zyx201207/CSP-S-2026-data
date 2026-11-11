#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2;
	string r1,r2;
	cin>>c1>>r1>>c2>>r2;
	int q1=c1[0]*10+c1[1],q2=c2[0]*10+c2[1];
	if(c1==c2) cout<<"1";
	else cout<<"0";
	//1
	int x=r1[0]*10+r1[1],y=r2[0]*10+r2[1];
	char z1=r1[2],z2=r2[2];
	if(x==y&&c1==c2){
		cout<<"1";
		if(z1=='D'&&z2=='F') cout<<"11";
		else if(z1=='F'&&z2=='D') cout<<"11";
		else if(z1=='A'&&z2=='B') cout<<"11";
		else if(z1=='A'&&z2=='C') cout<<"10";
		else if(z1=='B'&&z2=='C') cout<<"11";
		else if(z1=='B'&&z2=='A') cout<<"11";
		else if(z1=='C'&&z2=='A') cout<<"10";
		else if(z1=='C'&&z2=='B') cout<<"11";
		else cout<<"00";
	}else{
		cout<<"000";
	}
	return 0;
}