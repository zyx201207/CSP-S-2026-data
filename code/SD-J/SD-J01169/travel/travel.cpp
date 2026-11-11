#include <bits/stdc++.h>
using namespace std;
string s1,s2,c1,c2; 
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if ( c1!=c2 ) {
		printf("0000\n");
		return 0;
	}
	printf("1");
	if ( s1[0]==s2[0]&&s1[1]==s2[1] ) {
		printf("1");
		int k1=s1[2]-'A',k2=s2[2]-'A';
		if ( (k1>2&&k2>2)||(k1<=2&&k2<=2) ) {
			printf("1");
			if ( k1+1==k2||k2+1==k1 ) {
				printf("1");
			}
			else {
				if ( s1[2]=='D'&&s2[2]=='F'||s1[2]=='F'&&s2[2]=='D' )
					printf("1");
				else printf("0");
			}
		}
		else printf("00");
	}
	else printf("000");
	return 0;
}
