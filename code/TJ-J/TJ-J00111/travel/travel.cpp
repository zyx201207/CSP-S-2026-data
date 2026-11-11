#include<bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a1,a2,b1,b2;
	cin>>a1>>a2>>b1>>b2;
	bool f1=0,f2=0,f3=0,f4=0;
	if(a1==b1) {
		cout<<1;
		f1=1;
		if(a2[0]==b2[0] && a2[1]==b2[1]) {
			cout<<1;
			f2=1;
			if((a2[2]>=65 && a2[2]<=67) and (b2[2]>=65 && b2[2]<=67) && a2[2]!=b2[2]) {
				cout<<1;
				f3=1;
				if(a2[2]+1==b2[2] || a2[2]-1==b2[2]) {
					cout<<1;
					f4=1;
				}
			} else if((a2[2]==69 && b2[2]==71 || a2[2]==71 && b2[2]==69) && a2[2]!=b2[2]) {
				cout<<11;
				f3=1,f4=1;
			}
		}
	}
	
	
	if(!f1)cout<<0;
	if(!f2)cout<<0;
	if(!f3)cout<<0;
	if(!f4)cout<<0;
	return 0;
}
