#include<bits/stdc++.h>
using namespace std;
string a,b,x,y,c,s;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>a>>b>>x>>y;
	if(a==x)cout<<1;
	else {
		cout<<"0000";
		return 0;
	}
	c+=b[0],s+=y[0];
	c+=b[1],s+=y[1];
	if(c==s)cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	if((b[2]<='C'&&y[2]<='C')||(b[2]>'C'&&y[2]>'C'))cout<<1;
	else {
		cout<<"00";
		return 0;
	}
	if((b[2]<='C'&&y[2]<='C'&&(b[2]+1==y[2]||b[2]-1==y[2]))||(b[2]>'C'&&y[2]>'C'))cout<<1;
	else cout<<0;
	return 0;
}
