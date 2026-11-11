#include<bits/stdc++.h>
using namespace std;
int a,b,c,d;
string B,D;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>B>>c>>D;
	b=(B[0]-'0')*10+B[1]-'0';
	d=(D[0]-'0')*10+D[1]-'0';
	if(B[2]=='F')B[2]='E';
	if(D[2]=='F')D[2]='E';
	bool pa=(a==c),pb=(b==d),pc=((B[2]<='C'&&D[2]<='C')||(B[2]>'C'&&D[2]>'C')),pd=(abs(D[2]-B[2])==1);
	cout<<pa<<(pa&&pb)<<(pa&&pb&&pc)<<(pa&&pb&&pc&&pd);
	return 0;
}
