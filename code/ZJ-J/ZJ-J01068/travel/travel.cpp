#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int i,numa,numb,seata,seatb,s[10];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	for(i=0;i<2;i++) numa=numa*10+a[i]-'0';
	for(i=0;i<2;i++) numb=numb*10+c[i]-'0';
	for(i=0;i<2;i++) seata=seata*10+b[i]-'0';
	for(i=0;i<2;i++) seatb=seatb*10+d[i]-'0';
	if(numa==numb){
		s[1]=1;
		if(seata==seatb){
			s[2]=1;
			if(b[2]=='A'&&d[2]=='B'||b[2]=='A'&&d[2]=='C'||
			b[2]=='B'&&d[2]=='C'||b[2]=='B'&&d[2]=='A'||
			b[2]=='C'&&d[2]=='A'||b[2]=='C'&&d[2]=='B'||
			b[2]=='D'&&d[2]=='F'||b[2]=='F'&&d[2]=='D'){
				s[3]=1;
				if(b[2]=='A'&&d[2]=='B'||b[2]=='B'&&d[2]=='C'||
				b[2]=='B'&&d[2]=='A'||b[2]=='C'&&d[2]=='B'||
				b[2]=='D'&&d[2]=='F'||b[2]=='F'&&d[2]=='D'){
					s[4]=1;
				}
			}
		}
	}
	for(i=1;i<=4;i++) cout<<s[i];
}
