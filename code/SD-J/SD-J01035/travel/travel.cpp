#include<bits/stdc++.h>
#define int long long
using namespace std;
string c1,s1,c2,s2;
signed main(){
	ios::sync_with_stdio(false);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if (c1==c2) cout<<1;
	else cout<<0;
	
	if (c1==c2&&s1[1]==s2[1]&&s1[0]==s2[0]) cout<<1;
	else cout<<0;
	
	bool flag=0;
	if (c1==c2&&s1[1]==s2[1]&&s1[0]==s2[0]){
		if (s1[2]<='C'&&s2[2]>'C') {cout<<0;flag=1;}
		else if (s1[2]>'C'&&s2[2]<='C') {cout<<0;flag=1;}
		else {cout<<1;flag=1;}
	}
	if (flag==0) cout<<0;
	
	flag=0;
	if (c1==c2&&s1[1]==s2[1]&&s1[0]==s2[0]){
		if (s1[2]<='C'&&s2[2]>'C') {cout<<0;flag=1;}
		else if (s1[2]>'C'&&s2[2]<='C') {cout<<0;flag=1;}
		else if (abs((int)(s1[2])-(int)(s2[2]))==1) {cout<<1;flag=1;}
	}
	if(flag==0) cout<<0;
	return 0;
}
