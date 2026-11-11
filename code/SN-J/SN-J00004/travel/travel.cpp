#include<bits/stdc++.h>
using namespace std;
string rc,rs,xc,xs;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>rc>>rs>>xc>>xs;
	if(rc==xc)
		if(rs[0]==xs[0]&&rs[1]==xs[1])
			if(rs[2]<='C'&&xs[2]<='C'||rs[2]>='D'&&xs[2]>='D')
				if(abs(rs[2]-xs[2])==1||rs[2]>='D'&&xs[2]>='D')
					cout<<"1111";
				else
					cout<<"1110";
			else
				cout<<"1100";
		else
			cout<<"1000";
	else
		cout<<"0000";
	return 0;
}
