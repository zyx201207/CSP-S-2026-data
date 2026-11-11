#include<bits/stdc++.h>
using namespace std;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c,c1,s,s1;cin>>c>>s>>c1>>s1;
	if(c==c1){
		if(s[1]==s1[1]){
			char a=s[2],b=s1[2];
			if((a<='C'&&b<='C')||(a<='F'&&b<='F'&&a>'C'&&b>'C')){
				if(a+1==b||a-1==b) cout<<"1111";
				else cout<<"1110";
			}
			else cout<<"1100";
		}
		else cout<<"1000";
	}
	else cout<<"0000";
	return 0;
}

