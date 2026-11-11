#include<bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
bool ans[10];
inline bool f() {
	return ((s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C') && (s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C')) || ((s1[2] == 'D' || s1[2] == 'E') && (s2[2] == 'D' || s2[2] == 'E'));
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	memset(ans, 0, sizeof(ans));
	ans[0] = c1 == c2;
	ans[1] = ans[0] && (s1[0] == s2[0] && s1[1] == s2[1]);
	ans[2] = ans[1] && f();
	ans[3] = ans[2] && !(
	(s1[2] == 'A' && s2[2] == 'C') || (s1[2] == 'C' && s2[2] =='A')
	);
	for (int i = 0; i < 4; i++) {
        if(ans[i]) {
            printf("1");
        } else {
            printf("0");
        }
	}
	printf("\n");
	return 0;
}
