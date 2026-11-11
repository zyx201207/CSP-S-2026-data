#include<bits/stdc++.h>
using namespace std;
#define int long long
string s,t;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	s+=' '+t;
	cin>>t;
	s+=' '+t;
	cin>>t;
	s+=' '+t;
	cin>>t;
	s+=' '+t;
	if(s[1]==s[8]&&s[2]==s[9]){
		cout<<1;
		if(s[4]==s[11]&&s[5]==s[12]){
			cout<<1;
			if((s[6]<='C'&&s[13]<='C')||(s[6]>='D'&&s[13]>='D')){
				cout<<1;
				if(abs((int)(s[6]-s[13]))==1) cout<<1;
				else cout<<0;
			}else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
	return 0;
}
