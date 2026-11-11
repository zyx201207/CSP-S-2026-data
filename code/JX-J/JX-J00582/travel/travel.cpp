#include<bits/stdc++.h>
using namespace std;
int a1,a2,a3,a4;
bool k1,k2;
int main(){
	freopen("travel.in",'r',stdin);
	freopen("travel.out",'w',stdout);
	string c1,c2,c3,c4;
	cin>>c1>>c2>>c3>>c4;
	a1=c1[1]-'0'+10*(c1[0]-'0');
	a3=c3[1]-'0'+10*(c3[0]-'0');
	a2=c2[1]-'0'+10*(c2[0]-'0');
	a4=c4[1]-'0'+10*(c4[0]-'0');
	if(a1==a3){
		cout<<'1';
	if(a2==a4){
		cout<<'1';
	if(c2[2]<='C')k1=1;
	if(c4[2]<='C')k2=1;
	if(k1==k2){
		cout<<'1';
		if(c2[2]-c4[2]==1||c2[2]-c4[2]==-1)
		cout<<'1';
	else cout<<'0';
	}
	else cout<<"00";
	}
	else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
