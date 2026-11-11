#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
//	cin.tie(0)->sync_with_stdio(0);
	cin>>a>>b>>c>>d;
	if(a[0]==c[0]&&a[1]==c[1]) cout<<1;
	else return cout<<"0000",0;
	if(b[0]==d[0]&&b[1]==d[1]) cout<<1;
	else return cout<<"000",0;
	if(b[2]>='A'&&b[2]<='C'&&d[2]>='A'&&d[2]<='C'){
		cout<<1;
		if(abs(b[2]-d[2])==1) cout<<1;
		else return cout<<0,0;	
	}
	else if(b[2]>='D'&&b[2]<='F'&&d[2]>='D'&&d[2]<='F'){
		cout<<1;
		if(abs(b[2]-d[2])==1) cout<<1;
		else return cout<<0,0;	
	}
	else return cout<<"00",0;
	return 0;
}

