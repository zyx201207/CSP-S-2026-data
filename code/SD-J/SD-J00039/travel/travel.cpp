#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	string p1=s1.substr(0,2),p2=s2.substr(0,2);
	char st1=s1[2],st2=s2[2];
	if(c1!=c2)cout<<"0000\n";
	else if(p1!=p2)cout<<"1000\n";
	else if(((st1=='A'||st1=='B'||st1=='C')&&(st2=='A'||st2=='B'||st2=='C'))||((st1=='D'||st1=='F')&&(st2=='D'||st2=='F'))){
		if(abs((int)(st1-st2))==1)cout<<"1111\n";
		else cout<<"1110\n";
	}
	else cout<<"1100\n";
	return 0;
}
/*
02 01A 02 01B
02 01C 02 01A
02 01C 02 01D
02 02B 02 01A
02 01A 03 01A
02 01C 02 01D
*/
