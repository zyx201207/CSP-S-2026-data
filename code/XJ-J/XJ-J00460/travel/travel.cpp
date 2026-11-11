#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(false),cin.tie(0);
#define int long long
using namespace std;
int ans[] = {0, 0, 0, 0};
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	fast;
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2){
		ans[0] = 1;
		string sx = s1.substr(0,2), sc = s2.substr(0,2);
		if(sx == sc){
			ans[1] = 1;
			if(s1[2] == 'A'&& s2[2] == 'B') ans[2] = 1,ans[3] = 1;
			if(s1[2] == 'A'&& s2[2] == 'C') ans[2] = 1;
			if(s1[2] == 'B'&& s2[2] == 'C') ans[2] = 1,ans[3] = 1;
			if(s1[2] == 'D'&& s2[2] == 'F') ans[2] = 1,ans[3] = 1;
			if(s2[2] == 'A'&& s1[2] == 'B') ans[2] = 1,ans[3] = 1;
			if(s2[2] == 'A'&& s1[2] == 'C') ans[2] = 1;
			if(s2[2] == 'B'&& s1[2] == 'C') ans[2] = 1,ans[3] = 1;
			if(s2[2] == 'D'&& s1[2] == 'F') ans[2] = 1,ans[3] = 1;
		}
	}
	cout << ans[0] << ans[1] << ans[2] << ans[3];
	return 0;
}