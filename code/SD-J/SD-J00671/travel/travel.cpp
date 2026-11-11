#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
char ans1='1',ans2='0',ans3='0',ans4='0';
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >>s2;
	for (int i=0;i<c1.size();i++){
		if (c1[i]!=c2[i]){
			ans1='0';
			break;
		}
	}
	if (ans1=='1'){
		if (s1[0]==s2[0] and s1[1]==s2[1]) ans2='1';
		if (ans2=='1'){
			if (s1[2]=='A'){
				if (s2[2]=='B' or s2[2]=='C') ans3='1';
			}
			else if (s1[2]=='B'){
				if (s2[2]=='A' or s2[2]=='C') ans3='1';
			}
			else if (s1[2]=='C'){
				if (s2[2]=='A' or s2[2]=='B') ans3='1';
			}
			else if (s1[2]=='D' and s2[2]=='F') ans3='1';
			else if (s1[2]=='F' and s1[2]=='D') ans3='1';
			if (ans3=='1'){
				if ((s1[2]=='A' and s2[2]=='B') or (s1[2]=='B' and s2[2]=='C') or (s1[2]=='C' and s2[2]=='B') or (s1[2]=='D' and s2[2]=='F') or (s1[2]=='F' and s1[2]=='D')){
					ans4='1';
				}
			}
		}
	}
	cout << ans1 << ans2 << ans3 << ans4;
	return 0;
}
