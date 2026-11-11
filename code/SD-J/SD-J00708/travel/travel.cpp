#include <bits/stdc++.h>
using namespace std;

char c1[5], s1[5], c2[5], s2[5]; 
int ans[5];

int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	scanf("%s%s%s%s", c1 + 1, s1 + 1, c2 + 1, s2 + 1);
	memset(ans, 0, sizeof(ans));
	bool flag = 1;
	for(int i = 1; i <= 2; i++){
		if(c1[i] != c2[i])
		flag = 0;
	}
	if(flag == 1) 
		ans[1] = 1;
	if(s1[1] == s2[1] && s1[2] == s2[2] && ans[1] == 1)
		ans[2] = 1;
	if((s1[3] >= 'A' && s1[3] <= 'C') && (s2[3] >= 'A' && s2[3] <= 'C') && ans[2] == 1)
		ans[3] = 1;
	else if((s1[3] == 'D' || s1[3] == 'F') && (s2[3] == 'D' && s2[3] == 'F') && ans[2] == 1)
		ans[3] = 1;
	if((s1[3] == 'A' && s2[3] == 'B') || (s1[3] == 'B' && s2[3] == 'C') || (s1[3] == 'D' && s2[3] == 'F'))
		ans[4] = 1;
	for(int i = 1; i <= 4; i++)
		printf("%d", ans[i]);
	return 0;
} 
