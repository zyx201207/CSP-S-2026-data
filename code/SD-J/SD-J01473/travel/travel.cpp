#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	string c1, c2;
	string s1, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	int res[4] = {0, 0, 0, 0};
	
	if(c1 == c2){
		res[0]=1;
	} else {
		res[0]=res[1]=res[2]=res[3]=0;
	}
	for (int i = 0; i<4; i++){
		cout << res[i];
	}
	
	return 0;
}
