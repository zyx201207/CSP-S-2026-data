#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5;
string c1,s1,c2,s2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	int a=10*(c1[0]-'0')+c1[1]-'0';
	int b=10*(c2[0]-'0')+c2[1]-'0';
	if(a==b) cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	int x=10*(s1[0]-'0')+s1[1]-'0';
	int y=10*(s2[0]-'0')+s2[1]-'0';
	if(x==y) cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D')) cout<<1;
	else{
		cout<<"00";
		return 0;
	}
	if(abs(s1[2]-s2[2])==1) cout<<1;
	else cout<<0;
}
