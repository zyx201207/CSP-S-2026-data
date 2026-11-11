#include <bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a!=c) cout<<0<<0<<0<<0<<'\n';
	else{
		cout<<1;
		if(b[0]!=d[0] || b[1]!=d[1]) cout<<0<<0<<0<<'\n';
		else{
			cout<<1;
			if((b[2]<='C' && d[2]>'C') || (b[2]>'C' && d[2]<='C')) cout<<0<<0<<'\n';
			else{
				cout<<1;
				if((b[2]+1)==d[2]) cout<<1<<'\n';
				else if((b[2]-1)==d[2]) cout<<1<<'\n';
				else cout<<0<<'\n';
			}
		}
	}
	return 0;
}
