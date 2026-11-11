#include <bits/stdc++.h>
#define int long long
using namespace std;
string c1,s1,c2,s2;
int a[10]={1,1,1,2,2};
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2) cout<<"0000";
	else{
		cout<<"1";
		if((s1[0]!=s2[0])||(s1[1]!=s2[1])) cout<<"000";
		else{
			cout<<"1";
			if(a[s1[2]-'A']!=a[s2[2]-'A']) cout<<"00";
			else{
				cout<<"1";
				if((s1[2]=='A'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='A')) cout<<"0";
				else cout<<"1";
			}
		}
	}
}
