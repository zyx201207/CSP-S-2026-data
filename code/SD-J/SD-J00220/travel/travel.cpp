#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	string s1,c1,s2,c2;
	cin>>s1>>c1>>s2>>c2;
	if(s1==s2)cout<<1;
	else{
		cout<<"0000";
		return 0;
	}if(c1[0]+c1[1]==c2[0]+c2[1])cout<<1;
	else{
		cout<<"000";
		return 0;
	}if(c1[2]>='A'&&c1[2]<='C'&&c2[2]>='A'&&c2[2]<='C'){
		cout<<1;
		if(c1[2]+1==c2[2]||c1[2]-1==c2[2])cout<<1;
		else cout<<0;
	}else if(c1[2]>='D'&&c1[2]<='F'&&c2[2]>='D'&&c2[2]<='F'){
		cout<<1;
		if(c1[2]+2==c2[2]||c1[2]-2==c2[2])cout<<1;
		else cout<<0;
	}else cout<<"00";
	return 0;
} 
