#include  <bits/stdc++.h>
using namespace std;
long long a,c,tnt;
string b,d;
int  main() {
	freopen("travel.in ","r",stdin);
	freopen("travel.out ","w",stdout);
	cin>>a>>b>>c>>d; 
	cout<<a<<' '<<c<<' ';
	if (a!=c) {
		cout<<"0000";
		
	} else {
		cout<<1;
		if (b[1]==d[1] and b[0]==d[0]) {
			cout<<1;
			tnt=0;
			if(b[2]=='C' or b[2]=='B' or b[2]=='A'){
				if(d[2]=='D' or d[2]=='F') {
					cout<<"00";
					tnt=1;
				}
			}
			if(d[2]=='C' or d[2]=='B' or d[2]=='A'){
				if(b[2]=='D' or b[2]=='F') {
					cout<<"00";
					tnt=1;
				}
			}
			if (tnt==0) {
				cout<<1;
				if(b[2]=='A' or b[2]=='C') {
					if(d[2]=='A' or d[2]=='C') {
						cout<<0;
					} else {
						cout<<1;
					}
				} else {
					cout<<1;
				}
				
			}
			
		} else {
			cout<<"000";
		}
	}
	
	return 0;
}



