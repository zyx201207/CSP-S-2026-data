#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string xc,xs,rc,rs;
	cin>>rc>>rs>>xc>>xs;
	cout<<(rc==xc);
	cout<<((rc==xc)&&(rs.substr(0,2)==xs.substr(0,2)));
	cout<<((rc==xc)&&(rs.substr(0,2)==xs.substr(0,2))&&(!((rs[2]=='D'&&xs[2]=='C')||(xs[2]=='D'&&rs[2]=='C'))));
	cout<<((rc==xc)&&(rs.substr(0,2)==xs.substr(0,2))&&(!((rs[2]=='D'&&xs[2]=='C')||(xs[2]=='D'&&rs[2]=='C')))&&abs(rs[2]-xs[2])==1);
	return 0;
}
