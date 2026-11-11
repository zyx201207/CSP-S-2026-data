#include <bits/stdc++.h>
using namespace std;
string r,rs,x,xs;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>r>>rs>>x>>xs;
	string s ,k;
	s+= char(rs[0]);
	s+=char(rs[1]);
	k+= char(xs[0]);
	k+=char(xs[1]);
	if (r==x) {
		cout<<"1";
		if (s==k) {
			cout<<"1";
			if ((rs[2]<=67&&xs[2]<=67) || (rs[2]>=68&&xs[2]>=68)) {
				cout<<"1";
				if ( abs(rs[2]-xs[2])==1 && ((rs[2]!=67&&xs[2]!=68)||(rs[2]!=68&&xs[2]!=67)) ) {
					cout<<"1";	
				}
				else{
					cout<<"0";
					return 0;
				}
			}
			else {
				cout<<"00";
				return 0;
			}
		}
		else {
			cout<<"000";
			return 0;	
		}
		
	}
	else {
		cout<<"0000";
	}
	return 0;
}

