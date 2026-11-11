#include<bits/stdc++.h>
#define int long long
using namespace std;
string c1,c2,s1,s2;
bool ans=1;
signed main(){
	ios::sync_with_stdio(0),cin.tie(),cout.tie();
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>c2>>s1>>s2;
	if(c1==s1)cout<<ans;
	else{
		ans=0;
		cout<<ans;
	}
	if(c2[0]==s2[0]&&c2[1]==s2[1])cout<<ans;
	else{
		ans=0;
		cout<<ans;
	}
	if(c2[2]>='D'&&s2[2]>='D'||c2[2]<='C'&&s2[2]<='C')cout<<ans;
	else{
		ans=0;
		cout<<ans;
	}
	if(abs(c2[2]-s2[2])==1)cout<<ans;
	else{
		ans=0;
		cout<<ans;
	}
	return 0;
}
