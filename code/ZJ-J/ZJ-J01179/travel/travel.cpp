#include <bits/stdc++.h>
using namespace std;
string c1,z1,c2,z2;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>z1>>c2>>z2;
	if(c1!=c2) cout<<0<<0<<0<<0;
	else {
		cout<<1;
		if(z1[0]!=z2[0]||z1[1]!=z2[1]) cout<<0<<0<<0;
		else {
			cout<<1;
			if((z1[2]>'C'&&z2[2]>'C')||(z1[2]<='C'&&z2[2]<='C')) {
				cout<<1;
				if(abs(int(z1[2]-z2[2]))<=1) cout<<1;
				else cout<<0;
			}
			else cout<<0<<0;
		}
	}
	
	return 0;
}