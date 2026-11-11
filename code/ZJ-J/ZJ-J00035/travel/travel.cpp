#include<bits/stdc++.h>
using namespace std;
#define int long long
int a,b;
string s,t;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>a>>s>>b>>t;
	if(a==b){
		cout<<1;
		int c=0,d=0;
		c=(s[0]-'0')*10+s[1]-'0';
		d=(t[0]-'0')*10+t[1]-'0';
		if(c==d){
			cout<<1;
			if(s[2]<='C'&&t[2]<='C'){
				cout<<1;
				if(t[2]==s[2]+1||t[2]==s[2]-1) cout<<1;
				else cout<<0;
			}
			else if(s[2]>='D'&&t[2]>='D') cout<<11;
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
