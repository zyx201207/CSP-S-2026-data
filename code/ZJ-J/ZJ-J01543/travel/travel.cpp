#include<bits/stdc++.h>
#define int long long
using namespace std;
string s1,s2,s3,s4;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3){
		cout<<1;
	}else {
		cout<<"0000";return 0;
	}
	if(s2[0]==s4[0]&&s2[1]==s4[1]){
		cout<<1;
	}
	else{
		cout<<"000";return 0;
	}
	if(('A'<=s2[2]&&s2[2]<='C'&&'A'<=s4[2]&&s4[2]<='C')||('D'<=s2[2]&&s2[2]<='E'&&'D'<=s4[2]&&s4[2]<='E'))
		cout<<1;
	else {
		cout<<"00";return 0;
	}
	if(abs(s2[2]-s4[2])==1) cout<<1;
	else cout<<0;
	return 0;
}