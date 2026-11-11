#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
using ll=long long;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	fast;
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	
	if(c1==c2) cout<<1;
	else cout<<0;
	
	if(c1==c2){
		if(s1[0]==s2[0] && s1[1]==s2[1]) cout<<1;
		else cout<<0;
	}
	else cout<<0;
	
	if(c1==c2 && (s1[0]==s2[0] && s1[1]==s2[1])){
		if(s1[2]<='C'&&s2[2]<='C' || s1[2]>='D'&&s2[2]>='D') cout<<1;
		else cout<<0;
	}
	else cout<<0;
	
	if(c1==c2 && (s1[0]==s2[0] && s1[1]==s2[1]) && (s1[2]<='C'&&s2[2]<='C' || s1[2]>='D'&&s2[2]>='D')){
		if(s1[2]-s2[2]==1 || s1[2]-s2[2]==-1) cout<<1;
		else cout<<0;
	}
	else cout<<0;
	return 0;
}