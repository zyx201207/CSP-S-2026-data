#include<bits/stdc++.h>
using namespace std;
string cr,sr,cx,sx;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	bool a=0,b=0,c=0,d=0;
	cin>>cr>>sr>>cx>>sx;
	if(cr==cx)a=1;
	if(a==1&&sr[0]==sx[0]&&sr[1]==sx[1])b=1;
	if(b&&((sr[2]<='C'&&sx[2]<='C')||(sr[2]>='D'&&sx[2]>='D')))c=1;
	if(sr[2]>sx[2])swap(sr[2],sx[2]);
	if(c==1&&((sr[2]=='A'&&sx[2]=='B')||(sr[2]=='B'&&sx[2]=='C')||(sr[2]=='D'&&sx[2]=='F')))d=1;
	cout<<a<<b<<c<<d;
	return 0;
}
