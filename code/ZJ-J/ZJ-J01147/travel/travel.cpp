#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,x,b,y;
	bool p=1;
	cin>>a>>x>>b>>y;
	p&=(a[0]==b[0])&&(a[1]==b[1]);
	cout<<p;
	p&=(x[0]==y[0])&&(x[1]==y[1]);
	cout<<p;
	p&=(x[2]<='C')^(y[2]>'C');
	cout<<p;
	p&=abs(x[2]-y[2])==1;
	cout<<p;
}