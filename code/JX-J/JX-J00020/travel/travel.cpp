#include<bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
int ans1, ans2, ans3, ans4;
bool p1, p2;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> c1 >> s1 >> c2 >> s2;
    p1 |= bool(s1[2] == 'D');
    p1 |= bool(s1[2] == 'F');
    p2 |= bool(s2[2] == 'D');
    p2 |= bool(s2[2] == 'F');
	if(c1 == c2){
		ans1 = 1;
		if(s1[0] == s2[0] && s1[1] == s2[1]){
			ans2 = 1;
			if(p1 == p2){
				ans3 = 1;
				if(s1[2] == 'A' || s1[2] == 'C'){
					if(s2[2] == 'A' || s2[2] == 'C'){
						ans4 = 0;
					}else{
						ans4 = 1;
					}
				}else{
					ans4 = 1;
				}
			}
		}
	}
	cout << ans1 << ans2 << ans3 << ans4;
    return 0;
}
