#include<bits/stdc++.h>
using namespace std;
int main() {
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
	int e=0;
	char a[10];
	char b[10];
	char c[10];
	char d[10];
	cin>>a>>b>>c>>d;
	for(int i=0; i<2; i++) {
		if(a[i]==c[i]) {
			e++;
		}
	}
	if(e==2) {
		cout<<"1";
		e=0;
		for(int i=0; i<2; i++) {
			if(b[i]==d[i]) {
				e++;
			}
		}
		if(e==2) {
			cout<<"1";
			e=0;
			if(int(b[2])>int('C')&&int(d[2])>int('C')) {
				cout<<"1";
				e=1;
				if(int(b[2])-int(d[2])==1||int(b[2])-int(d[2])==-1) {
					cout<<"1";
				} else {
					cout<<"0";
				}
			}
			if(int(b[2])<int('D')&&int(d[2])<int('D')) {
				cout<<"1";
				e=1;
				if(int(b[2])-int(d[2])==1||int(b[2])-int(d[2])==-1) {
					cout<<"1";
				} else {
					cout<<"0";
				}
			}
			if(e==0) {
				cout<<"00";

				return 0;
			}

		}else {
		cout<<"000";
	} 
	} else {
		cout<<"0000";

	}
}

