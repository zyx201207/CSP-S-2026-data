//李铭宸 西安交通大学附属中学 SN-J00830
#include <bits/stdc++.h>
using namespace std;
string n,m,p,q;
string s;
bool pi( ) {
	if(m[0]==q[0]&&m[1]==q[1]) {
		return 1;
	}
	return 0;
}
void co(int n) {
	for(int i=n; i<=4; i++) {
		s[i]='0';
	}
}
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>m>>p>>q;
	if(n==p) {
		s[1]='1';
		if(pi( )) {
			s[2]='1';
			bool mf=0,qf=0;
			if(m[2]>='A'&&m[2]<='C') {
				mf=1;
			}
			if(q[2]>='A'&&q[2]<='C') {
				qf=1;
			}
			if(mf==qf) {
				s[3]='1';
				if(abs(m[2]-q[2])==1&&mf==qf) {
					s[4]='1';
				} else {
					co(4);
				}
			} else {
				co(3);
			}
		} else {
			co(2);
		}
	} else {
		co(1);
	}
	for(int i=1;i<=4;i++)
	{
		cout<<s[i];
	}
	return 0;
}
