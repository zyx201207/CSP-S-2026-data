#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll,ll>
#define S second
#define F first
const ll N=1e6+5,mod=1e9+7,inf=1e18;
string a,b,s1,s2;
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>s1>>b>>s2;
	if(a==b){
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='A')) cout<<"1111";
			else if((s1[2]=='A'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='A')) cout<<"1110";
			else if((s1[2]=='B'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='B')) cout<<"1111";
			else if((s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')) cout<<"1111";
			else cout<<"1100";
		}
		else cout<<"1000";
	}
	else cout<<"0000";
	return 0;
}

