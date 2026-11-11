#include<bits/stdc++.h> 
using namespace std;
int a,c;
bool aa,bb;
string b,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c)cout<<1;
	else{
		cout<<"0000";
		return 0; 
	}
	if(b[0]==d[0]&&b[1]==d[1])cout<<1;
	else{
		cout<<"000";
		return 0; 
	}
	if(b[2]>='A'&&b[2]<='C')aa=true;
	if(d[2]>='A'&&d[2]<='C')bb=true;
	if(aa==bb&&b[0]==d[0]&&b[1]==d[1])cout<<1;
	else{
		cout<<"00";
		return 0; 
	}
	if(aa==bb&&abs((int)d[2]-b[2])==1)cout<<1;
	else{
		cout<<"0";
		return 0; 
	}
	return 0;
}
