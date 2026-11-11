#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int cnt1,cnt2,cnt3,cnt4; 
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	
	if(c1 == c2){
		cnt1++;
	}
	if(cnt1 == 1 && (s1[0]+s1[1] == s2[0]+s2[1])){
		cnt2++;
	}
	if(cnt2 == 1 && (s1[2] < 'D' && s2[2] < 'D' || s1[2] >= 'D' &&s2[2] >='D')){
		cnt3++;
	}
	if(cnt3 == 1 && abs(s1[2]-s2[2]) == 1){
		cnt4++;
	}
	cout << cnt1 << cnt2 << cnt3 << cnt4;
	
	return 0;
} 
