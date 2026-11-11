#include<bits/stdc++.h>
#define int long long
using namespace std;
string c1,c2,s1,s2,ss1,ss2;
char cs1,cs2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)cout<<1; else{
		cout<<"0000",exit(0);	
	}
	ss1=s1[0]+s1[1];
	ss2=s2[0]+s2[1];
	if(ss1==ss2)cout<<1; else{
		cout<<"000",exit(0);
	}
	cs1=s1[2],cs2=s2[2];
	if(cs1<='C'&&cs2<='C'||cs1>='D'&&cs2>='D')cout<<1;
	else{
		cout<<"00",exit(0);
	}
	if(cs1-1==cs2||cs2-1==cs1)cout<<1;
	else cout<<0;
	return 0;
}