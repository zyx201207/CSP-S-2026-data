#include <bits/stdc++.h>
using namespace std;
#define int long long
string a,b,c,d;
bool f1=false,f2=false,f3=false;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		f1=true;
		cout<<1;
	} else {
		cout<<0;
	}
	if(f1==true&&b[0]==d[0]&&b[1]==d[1]){
		f2=true;
		cout<<1;
	} else {
		cout<<0;
	}
	if(f1&&f2==true){
		if((d[2]>='A'&&d[2]<='C')&&(b[2]>='A'&&b[2]<='C')){
			f3=true;
			cout<<1;
		}
		if((d[2]=='D'||d[2]<='F')&&(b[2]=='D'||b[2]=='F')){
			f3=true;
			cout<<1;
		}
		if(f3==false) cout<<0;
	} else {
		cout<<0;
	}
	if(f1==true&&f2==true&&f3==true){
		if(abs(d[2]-b[2])==1) cout<<1;
		else cout<<0;
	} else {
		cout<<0;
	}
	return 0;
}
