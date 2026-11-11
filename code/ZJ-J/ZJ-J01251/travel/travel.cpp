#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
bool a1,b1,c1;
int main(){
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<1;
		a1=1;
	}
	else cout<<0;
	if(a1 && b[0]==d[0] && b[1]==d[1]){
		cout<<1;
		b1=1;
	}
	else cout<<0;
	if(b1 && ((b[2]<='C' && d[2]<='C') || (b[2]>'C' && d[2]>'C'))){
		cout<<1;
		c1=1;
	}
	else cout<<0;
	if(c1 && (b[2]>'C' || abs(int(b[2])-int(d[2]))==1)) cout<<1;
	else cout<<0;
	return 0;
}
