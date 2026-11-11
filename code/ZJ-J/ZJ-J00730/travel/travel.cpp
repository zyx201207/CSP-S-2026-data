#include<bits/stdc++.h>
#define int long long
using namespace std;
string c1,s1,c2,s2;
signed main(){
	cin.sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(s1[2]=='F')s1[2] = 'E';
	if(s2[2]=='F')s2[2] = 'E';
	if(c1==c2)cout<<"1";
	else{
		cout<<"0000";
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1])cout<<"1";
	else{
		cout<<"000";
		return 0;
	}
	int l1 = 0,l2 = 0;
	if(s1[2]<='C')l1 = 1;
	if(s2[2]<='C')l2 = 1;
	if(l1==l2){
		cout<<"1";
	}else{
		cout<<"00";
		return 0;
	}
	if(abs(s1[2]-s2[2])==1){
		cout<<"1";
	}else cout<<"0";
	return 0;
} 
