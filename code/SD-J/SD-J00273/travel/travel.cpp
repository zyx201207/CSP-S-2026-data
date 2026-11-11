#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	//A B C  D F
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s1_1,s1_2,s2_1,s2_2;
	cin>>s1_1>>s1_2>>s2_1>>s2_2;
	if(s1_1[0]==s2_1[0] && s1_1[1]==s2_1[1]) {
		cout<<"1";
		if(s1_2[0]==s2_2[0] && s1_2[1]==s2_2[1]) {
			cout<<"1";
			if(s1_2[2]=='A') {
				if(s2_2[2]=='B') cout<<"11";
				else if(s2_2[2]=='C') cout<<"10";
				else cout<<"00";
			}
			else if(s1_2[2]=='B') {
				if(s2_2[2]=='A' || s2_2[2]=='C') cout<<"11";
				else cout<<"00";
			}
			else if(s1_2[2]=='C') {
				if(s2_2[2]=='A') cout<<"10";
				else if(s2_2[2]=='B') cout<<"11";
				else cout<<"00";
			}
			else if(s1_2[2]=='D') {
				if(s2_2[2]=='F') cout<<"11";
				else cout<<"00";
			}
			else {
				if(s2_2[2]=='D') cout<<"11";
				else cout<<"00";
			}
		}
		else {
			cout<<"000";
		}
	}
	else {
		cout<<"0000";
	}
	return 0;
}
