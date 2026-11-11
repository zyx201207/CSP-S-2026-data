#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	int e=0,f=0,g=0,h=0,i=1,j=1;
	if(a==c){
		e=1;
		if(b[0]==d[0] and b[1]==d[1]){
			f=1;
			if(b[2]=='A' or b[2]=='B' or b[2]=='C') i=0;
			if(d[2]=='A' or d[2]=='B' or d[2]=='C') j=0;
			if(i==j) g=1;
			if((b[2]=='A'&&d[2]=='B')||(b[2]=='B'&&d[2]=='A')||(b[2]=='B'&&d[2]=='C')||(b[2]=='C'&&d[2]=='B')||(b[2]=='D'&&d[2]=='F')||(b[2]=='F'&&d[2]=='D')) h=1;
		}
		else{
			f=0;
			g=0;
			h=0;
		}
	}
	else{
		e=0;
		f=0;
		g=0;
		h=0;
	}
	printf("%d%d%d%d",e,f,g,h);
	fclose(stdin);
	fclose(stdout);
	return 0;
}