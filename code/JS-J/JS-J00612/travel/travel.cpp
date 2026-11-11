#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d,e;
    cin>>a>>b>>c>>d;
    if(a==c) cout<<"1";
    else{
		cout<<"0000";
		return 0;
	} 
	int m,n;
	m=b[0]+'0';
	m*=10;
	m+=b[1]+'0';
	n=d[0]+'0';
	n*=10;
	n+=d[1]+'0';
	if(m==n) cout<<"1";
	else{
		cout<<"000";
		return 0;
	}
	if((b[2]=='A' || b[2]=='B' || b[2]=='C') && (d[2]=='A' || d[2]=='B' || d[2]=='C')){
		cout<<1;
	}
	else if((b[2]=='D' || b[2]=='E') && (d[2]=='D' || d[2]=='E')){
		cout<<"1";
	}
	else {
		cout<<"00";
		return 0;
	}
	if(abs(b[2]-d[2])==1) cout<<"1";
	else cout<<"0";
    return 0;
}
