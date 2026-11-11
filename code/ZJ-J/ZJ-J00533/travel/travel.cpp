#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4,ans="0000";
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3){
		ans[0]='1';
		if(s2[0]==s4[0]&&s2[1]==s4[1]){
			ans[1]='1';
			if((s2[2]<='C'&&s4[2]<='C')||(s2[2]>'C'&&s4[2]>'C')){
				ans[2]='1';
				if(s2[2]<='C'&&abs(s2[2]-s4[2])==1){
					ans[3]='1';
				}
				if(s2[2]>'C'){
					ans[3]='1';
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
