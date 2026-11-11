#include <bits/stdc++.h>
using namespace std;
int ans[10];
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int c1, c2;
	string s1, s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		ans[1]=1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]) {
			ans[2]=1;
			if(s1[2]=='A') s1[2]='1';
			if(s1[2]=='B') s1[2]='2';
			if(s1[2]=='C') s1[2]='3';
			if(s1[2]=='D') s1[2]='8';
			if(s1[2]=='F') s1[2]='9';
			
			if(s2[2]=='A') s2[2]='1';
			if(s2[2]=='B') s2[2]='2';
			if(s2[2]=='C') s2[2]='3';
			if(s2[2]=='D') s2[2]='8';
			if(s2[2]=='F') s2[2]='9';
			
			if(abs(s1[2]-s2[2]) <= 3) {
				ans[3]=1;
				if(abs(s1[2]-s2[2]) <= 1) {
					ans[4]=1;
				}
			}
		}
	}
	for(int i=1; i<=4; ++i) cout << ans[i];
}
