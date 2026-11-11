#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b,c,d;
	string x1,y1,x2,y2;
	cin>>x1>>x2>>y1>>y2;
	if(x1[1]==y1[1]&&x1[0]==y1[0]) {
		a=1;
		if(x2[1]==y2[1]&&x2[0]==y2[0]) {
			b=1;
			if(x2[2]>=65&&x2[2]<=67&&y2[2]>=65&&y2[2]<=67) {
				c=1;
				if(abs(x2[2]-y2[2])==1) {
					d=1;
				} else {
					d=0;
				}
			} else if(x2[2]>=68&&x2[2]<=70&&y2[2]>=68&&y2[2]<=70) {
				c=1,d=1;
			} else {
				c=0,d=0;
			}
		} else {
			b=0,c=0,d=0;
		}
	} else {
		a=0,b=0,c=0,d=0;
	}
	cout<<a<<b<<c<<d;
	return 0;
}
