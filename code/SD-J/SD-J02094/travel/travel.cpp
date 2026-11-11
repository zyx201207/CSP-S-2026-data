#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4,ans;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3){
		if(s2[0]==s4[0]&&s2[1]==s4[1]){
			if((s2[2]<='C'&&s4[2]<='C')||(s2[2]>='D'&&s4[2]>='D')){
				int s=s2[2],ss=s4[2];
				if(abs(s-ss)==1) cout<<"1111";
				else cout<<"1110";
			}
			else cout<<"1100";
		}
		else cout<<"1000";
	}
	else cout<<"0000";
	return 0;
}
