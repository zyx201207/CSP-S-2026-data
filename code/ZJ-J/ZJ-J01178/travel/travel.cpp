#include <bits/stdc++.h>
using namespace std;
string s,s1,ss,ss1;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s>>s1>>ss>>ss1;
	if(s==ss){
		cout<<1;
		int ans,ans1;
		ans=10*(s1[0]-'0')+(s1[1]-'0');
		ans1=10*(ss1[0]-'0')+(ss1[1]-'0');
		if(ans==ans1) {
			cout<<1;
			if(s1[2]<'D' && ss1[2]<'D' || s1[2]>='D' && ss1[2]>='D') {
				cout<<1;
				if(abs(s1[2]-ss1[2])==1)cout<<1;
				else cout<<"0";
			} else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}