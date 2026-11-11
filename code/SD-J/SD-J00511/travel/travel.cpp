#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
bool boA,boB,boC,boD;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	boA=(a==c);
	string B=b.substr(0,2),D=d.substr(0,2);
	boB=(a==c && B==D);
	int X=b[2]-'A'+1,Y=d[2]-'A'+1;
	if(((X>3 && Y>3) || (X<=3 && Y<=3)) && boA && boB) boC=1;
	else boC=0;
	if(boA && boB && boC){
		if(abs(X-Y)==1)boD=1;
		else boD=0;
	}
	else boD=0;
	cout<<boA<<boB<<boC<<boD;
	return 0;
}
/*
#1
02 01A 02 01B
#2
02 01C 02 01A
#3
02 01C 02 01D
#4
02 02B 02 01A
#5
02 01A 03 01A
*/
