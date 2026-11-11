#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
string c,c1,z,z1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>z>>c1>>z1;
	if(c==c1){
		cout<<1;
	}
	else{
		cout<<"0000";
		return 0;
	}
	if(z[0]==z1[0]&&z[1]==z1[1]){
		cout<<1;
	}
	else{
		cout<<"000";
		return 0;
	}
	if(z[2]=='A'&&z1[2]=='B'||z[2]=='A'&&z1[2]=='C'||z[2]=='B'&&z1[2]=='C'||z[2]=='B'&&z1[2]=='A'||z[2]=='C'&&z1[2]=='A'||z[2]=='C'&&z1[2]=='B'||z[2]=='D'&&z1[2]=='F'||z[2]=='F'&&z1[2]=='D'){
		cout<<1;
	}
	else{
		cout<<"00";
		return 0;
	}
	int a,b;
	a=z[2],b=z1[2];
	if(abs(a-b)==1){
		cout<<1;
	}
	else {
		cout<<0;
		return 0;
	}
	return 0;
}
