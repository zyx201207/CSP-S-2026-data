#include<bits/stdc++.h>
using namespace std;
#define int long long
string c1,s1,c2,s2;
bool f=false;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<1;
	else{
		f=true;
		cout<<0;
	}
	if(f==true) cout<<0;
	else{
		if(s1[0]==s2[0] && s1[1]==s2[1]) cout<<1;
		else{
			f=true;
			cout<<0;
		}
	}
	if(f==true) cout<<0;
	else{
		if(s1[2]<='C' && s2[2]<='C') cout<<1;
		else if(s1[2]>'C' && s2[2]>'C') cout<<1;
		else{
			f=true;
			cout<<0;
		}
	}
	if(f==true) cout<<0;
	else{
		int a=abs((int)(s1[2]-s2[2]));
		if(a==1) cout<<1;
		else cout<<0;
	}
	return 0;
}
