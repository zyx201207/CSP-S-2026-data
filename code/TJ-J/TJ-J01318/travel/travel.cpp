#include <bits/stdc++.h>
#define int long long
using namespace std;
string c1, s1, c2, s2;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1 == c2){
		if(s1[0] == s2[0] && s1[1] == s2[1]){
			char s1l = s1[2], s2l = s2[2];
			if(s1l > s2l) swap(s1l, s2l);
			if((s1l == 'A' && s2l == 'B')||(s1l == 'A' && s2l == 'C')||(s1l == 'B' && s2l == 'C')||(s1l == 'D' && s2l == 'F')){
				if((s1l == 'A' && s2l == 'B')||(s1l == 'B' && s2l == 'C')||(s1l == 'D' && s2l == 'F')){
					cout<<"1111";
				}else cout<<"1110";
			}else cout<<"1100";
		}else cout<<"1000";
	}else cout<<"0000";
	return 0;
}
