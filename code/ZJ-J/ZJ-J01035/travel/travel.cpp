#include <bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
int ans[5];
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 != c2){
		printf("0000");
		return 0;
	}
	ans[1] = 1;
	bool s = 1;
	for(int i = 0;i <= 1;i ++){
		if(s1[i] != s2[i]){
			s = 0;
		}
	}
	if(s){
		ans[2] = 1;
		if((s1[2] <= 'C' && s2[2] <= 'C') || (s1[2] >= 'D' && s2[2] >= 'D')){
			ans[3] = 1;
		}
		if(abs(s1[2] - s2[2]) == 1 && !(s1[2] == 'C' && s2[2] == 'D') && !(s2[2] == 'C' && s1[2] == 'D')){
			ans[4] = 1;
		}
	}
	for(int i = 1;i <= 4;i ++){
		printf("%d", ans[i]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}