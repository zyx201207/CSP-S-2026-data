#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
//const int N = 
bool check1(char c1,char c2){
	char mi = min(c1,c2),ma = max(c1,c2);
	if (mi >= 'D') return 1;
	if (ma <= 'C') return 1;
	return 0;
}
bool check2(char c1,char c2){
	char mi = min(c1,c2),ma = max(c1,c2);
	if ((int)ma-(int)mi == 1) return 1;
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	string s1,s2,s3,s4; cin >> s1 >>s2>>s3>>s4;
	bool flag1=0,flag2=0,flag3=0;
	if (s1 == s3){
		cout <<"1";
		flag1 = 1;
	}else cout <<"0";
	if (flag1 && s2[0]==s4[0] && s2[1]==s4[1]){
		cout <<"1";
		flag2 = 1;
	}else cout <<"0";
	if (flag2 && check1(s2[2],s4[2])){
		cout <<"1";
		flag3 = 1;
	}else cout <<"0";
	if (flag3 && check2(s2[2],s4[2])) cout <<"1";
	else cout <<"0";
	return 0;
}
