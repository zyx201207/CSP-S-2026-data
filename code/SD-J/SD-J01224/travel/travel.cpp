#include<bits/stdc++.h>
using namespace std;
string c1,c2;
char s1[10],s2[10];

int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1+1;
	cin>>c2>>s2+1;
	int n=strlen(s1+1),m=strlen(s2+1);
	if (c1==c2) {
		bool f=1;
		for (int i=1;i<n;i++) {
			if (s1[i]!=s2[i]) f=0;
		}
		if (f) {
			if (int(s1[n])<=67&&int(s2[n])<=67) {
				int a,b;
				a=int(s1[n]),b=int(s2[n]);
				if (abs(a-b)==1) cout<<"1111"<<'\n';
				else cout<<"1110"<<'\n';
			}
			else if (int(s1[n])>67&&int(s2[n])>67) {
				int a,b;
				a=int(s1[n]),b=int(s2[n]);
				if (abs(a-b)==1) cout<<"1111"<<'\n';
				else cout<<"1110"<<'\n';				
			}
			else cout<<"1100"<<'\n';
		}
		else cout<<"1000"<<'\n';
	}
	else cout<<"0000"<<'\n';
	return 0;
}
//02 01A 02 01B 1111
//02 01C 02 01A 1110
//02 01C 02 01D 1100
//02 02B 02 01A 1000
