#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int m=0,n=0,p=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<1;
		m=1;
	}
	else    cout<<0;
	if(b[0]==d[0]&&b[1]==d[1]&&m==1){
		cout<<1;
		n=1;
	}    
	else    cout<<0;
	if((b[2]<='C'&&d[2]<='C'||b[2]>='D'&&d[2]>='D')&&b[2]!=d[2]&&m==1&&n==1){
		cout<<1;
		p=1;
	}
	else    cout<<0;
	if(abs(b[2]-d[2])==1&&m==1&&p==1&&n==1)    cout<<1;
	else    cout<<0;
	return 0;
}