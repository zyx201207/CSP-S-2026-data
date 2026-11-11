#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a!=c) cout<<"0000";
	else{
		cout<<"1";
		if(b[0]!=d[0]||b[1]!=d[1]) cout<<"000";
		else{
			cout<<"1";
			if(!(b[2]<='C'&&d[2]<='C'||b[2]>'C'&&d[2]>'C')) cout<<"00";
			else{
				cout<<"1";
				if(abs(b[2]-d[2])!=1) cout<<"0";
				else cout<<"1";
			}
		}
	}
	cout<<flush;
	fclose(stdin),fclose(stdout);
	return 0;
}
