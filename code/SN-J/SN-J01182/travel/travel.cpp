#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b,c,d;
	char e,f;
	cin>>a>>b>>e>>c>>d>>f;
	if(a!=c) cout<<"0000";
	else{
		cout<<"1";
		if(b!=d) cout<<"000";
		else{
			cout<<"1";
			if((e-'A'-2<=0)!=(f-'A'-2<=0)) cout<<"00";
			else{
				cout<<"1";
				if(abs(e-f)!=1) cout<<"0";
				else cout<<"1";
			}
		}
	}
	return 0;
}
