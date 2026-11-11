#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c) cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	if(b.substr(0,2)==d.substr(0,2)) cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	int f1=0,f2=0;
	if(b[2]>='A'&&b[2]<='C') f1=1;
	else f1=2;
	if(d[2]>='A'&&d[2]<='C') f2=1;
	else f2=2;
	if(f1==f2) cout<<1;
	else{
		cout<<"00";
		return 0;
	}
	int x=b[2]-'A',y=d[2]-'A';
	if(abs(x-y)==1) cout<<1;
	else cout<<0;
	return 0;
}
