#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
long long a,b,n,m;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c1>>c2>>s1>>s2;
	if(c1==s1) {
		cout<<"1";
		for(int i=0; i<c2.size(); i++) {
			for(int j=0; j<s2.size(); j++) {
				b++;
				if(i==j) {
					a++;
				}
				if(a>=2) {
					cout<<"1"<<"0"<<"0";
					return 0;
					if(b==9&&((i=='A'||i=='B'||i=='C')&&(j=='A'||j=='B'||j=='C'))||((i=='F'||i=='D')&&(j=='F'||j=='D'))) {
						cout<<"1";
						if(i=='B'||j=='B') {
							cout<<"1";
						} else {
							cout<<"0";
							return 0;
						}
						if(i=='F'||j=='F') {
							cout<<"1";
						} else {
							cout<<"0";
							return 0;
						}
					} else if(i!=3) {
						cout<<"0"<<"0";
						return 0;
					}
				} else if(b>4&&a<2) {
					cout<<"0"<<"0"<<"0";
					return 0;
				}
			}
		}
	} else {
		cout<<"0"<<"0"<<"0"<<"0";
		return 0;
	}
	return 0;
}
