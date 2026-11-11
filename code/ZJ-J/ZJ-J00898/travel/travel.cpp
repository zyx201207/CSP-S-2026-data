#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int lena,lenb,lenc,lend,A,B,C,D,bb,dd;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>a>>b>>c>>d;
	lena=a.size();lenb=b.size();
	lenc=c.size();lend=d.size();
	for(int i=0;i<=lena-1;i++){A=A*10+(int)(a[i]-48);}
	for(int i=0;i<=lenb-2;i++){B=B*10+(int)(b[i]-48);}
	if(b[lenb-1]=='A'){bb=1;}
	else if(b[lenb-1]=='B'){bb=2;}
	else if(b[lenb-1]=='C'){bb=3;}
	else if(b[lenb-1]=='D'){bb=4;}
	else{bb=5;}
	for(int i=0;i<=lenc-1;i++){C=C*10+(int)(c[i]-48);}
	for(int i=0;i<=lend-2;i++){D=D*10+(int)(d[i]-48);}
	if(d[lend-1]=='A'){dd=1;}
	else if(d[lend-1]=='B'){dd=2;}
	else if(d[lend-1]=='C'){dd=3;}
	else if(d[lend-1]=='D'){dd=4;}
	else{dd=5;}
	if(A==C){cout<<"1";}
	else{cout<<"0";}
	if(A==C&&B==D){cout<<"1";}
	else{cout<<"0";}
	if(A==C&&B==D&&((bb<=3&&dd<=3)||(bb>=4&&dd>=4))){
		cout<<"1";
		if(abs(bb-dd)==1){cout<<"1";}
		else{cout<<"0";}
	}else{cout<<"00";}
	return 0;
}