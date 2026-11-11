#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1 , c2 ,ans[5] = {};
	char s1[4] , s2[4];
	cin >> c1;
	for (int i = 1; i <= 3 ; i++){
		cin >> s1[i];
	}
	cin >> c2;
		for(int i = 1 ; i <= 3 ; i++){
		cin >> s2[i];
	}
	if(c1 == c2){
		ans[1] = 1;
	}
	int a[3] , b [3];
	for(int i = 1 ; i <= 2 ; i++){
		a[i] = s1[i];
		b[i] = s2[i];
	}
		if(a[1] == b[1] && a[2] == b[2] && ans[1] == 1){
			ans[2] = 1;
		}
		char ss = s1[3], sss = s2[3];
		if(ss == sss && ans[1] == 1 && ans[2] == 1){
			ans[3] = 1;
		}
	cout << ans[1] << ans[2] << ans[3] << 0 ; 
	return 0;
}
