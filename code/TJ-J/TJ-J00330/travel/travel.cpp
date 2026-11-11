#include<bits/stdc++.h>
#define int long long
using namespace std;
string s2,c2,s1,c1;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	int a=0,b=0,c=0;
	if(c1==c2){
		cout<<1;
		c=1;
	}
	else cout<<0;
	if(c==1&&s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<1;
		a=1;
	}
	else cout<<0;
	if(c==1&&a==1&&(s1[2]>'C')==(s2[2]>'C')){
		cout<<1;
		b=1;
	}
	else cout<<0;
	if(c==1&&b==1&&abs(s1[2]-s2[2])==1)cout<<1;
	else cout<<0;
	return 0;
}
