#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>c>>b>>d;
	bool e=1;
	if(a!=b){
		e=0;
	}
	cout<<e;
	if(c[0]!=d[0]||c[1]!=d[1]){
		e=0;
	}
	cout<<e;
	if((c[2]<='C'&&d[2]>'C')||(c[2]>'C'&&d[2]<='C')){
		e=0;
	}
	cout<<e;
	if(max(c[2],d[2])-min(c[2],d[2])>1||min(c[2],d[2])=='C'){
		e=0;
	}
	cout<<e;
	return 0;
}
