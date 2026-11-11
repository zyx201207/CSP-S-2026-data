#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool ans[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 != c2){
		cout << "0000\n";return 0;
	}else{
		ans[1]=1;
		if(s1[0]==s2[0] && s1[1]==s2[1]){
			ans[2]=1;ans[3]=1;
			if((s1[2]>'C'&&s2[2]<'D')||(s1[2]<'D'&&s2[2]>'C')){
				ans[3]=0;
				ans[4]=0;
				cout << ans[1] << ans[2] << ans[3] << ans[4];return 0;
			}
		}
		if(ans[3] == 1){
			int x=0+s1[2];
			int y=0+s2[2];
			if(abs(x-y)<2){
				ans[4]=1;
			}else if((s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')){
				ans[4]=1;
			}
		}
	}
	cout << ans[1] << ans[2] << ans[3] << ans[4];
	return 0;
}
