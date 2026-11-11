#include <bits/stdc++.h>
using namespace std;
int ans1, ans2, ans3, ans4;
string cr, sr, cx, sx;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> cr >> sr >> cx >> sx;
	if (cr == cx){
		ans1 = 1;
		if (sr[0] == sx[0] and sr[1] == sx[1]){
			ans2 = 1;
			if (((sr[2] == 'A' or sr[2] == 'B' or sr[2] == 'C') and (sx[2] == 'A' or sx[2] == 'B' or sx[2] == 'C')) or ((sr[2] == 'D' or sr[2] == 'F') and (sx[2] == 'D' or sx[2] == 'F'))){
				ans3 = 1;
				if((sr[2] == 'A' and sx[2] =='B') or (sr[2] == 'B' and sx[2] =='A')){
					ans4 = 1;
				}
				if((sr[2] == 'B' and sx[2] =='C') or (sr[2] == 'C' and sx[2] =='B')){
					ans4 = 1;
				}
				if((sr[2] == 'D' and sx[2] =='F') or (sr[2] == 'F' and sx[2] =='D')){
					ans4 = 1;
				}
			}
		}
	}
	printf("%d%d%d%d", ans1, ans2, ans3, ans4);
	return 0;
} 
