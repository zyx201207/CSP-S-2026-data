#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b,x,y;
	char c,z;
	cin>>a>>b>>c>>x>>y>>z;
	if(a==x) cout<<1;
	else {
		cout<<"0000";
		return 0;
	}
	if(b==y) cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	if((c<='C' && z<='C')||(c>'C' && z>'C')) cout<<1;
	else{
		cout<<"00";
		return 0;
	}
	if(abs(c-z)==1) cout<<1;
	else cout<<0;
	return 0;
}
