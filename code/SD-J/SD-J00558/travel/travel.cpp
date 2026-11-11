#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("travel.in","r",stdin);
	freopen("trevel.out","w",stdout);
	int n1,n2;
	string s1,s2;
	cin>>n1>>s1>>n2>>s2;
	bool f=1;
	if(n1==n2) {
		cout<<"1";
		for(int i=0; i<2; i++) {
			if(s1[i]!=s2[i]) {
				f=0;
			}
		}
		if(f==1) {
			cout<<"1";
			if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C') {
				if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C') {
					cout<<"1";
					if(s1[2]==char(int(s2[2])-1)||s1[2]==char(int(s2[2])+1)) {
						cout<<"1";
					} else {
						cout<<"0";
					}
				} else {
					cout<<"0";
					cout<<"0";
				}
			} else {
				if(s2[2]=='D'||s2[2]=='E') {
					cout<<"1";
					if(s1[2]==char(int(s2[2])-1)||s1[2]==char(int(s2[2])+1)) {
						cout<<"1";
					} else {
						cout<<"0";
					}
				} else {
					cout<<"0";
					cout<<"0";
				}
			}
		} else {
			cout<<"0";
			cout<<"0";
			cout<<"0";
		}
	} else {
		cout<<"0";
		cout<<"0";
		cout<<"0";
		cout<<"0";
	}
	return 0;
}
