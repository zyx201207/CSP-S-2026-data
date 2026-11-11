#include<bits/stdc++.h>
using namespace std;
#define int long long
string c1,s1,c2,s2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
	}else{
		cout<<"0000";
		return 0;
	}if(s1[0]==s2[0] and s1[1]==s2[1]){
	}else{
		cout<<"1000";
		return 0;
	}if((s1[2]>'C' and s2[2]>'C') or (s1[2]<='C' and s2[2]<='C')){
	}else{
		cout<<"1100";
		return 0;
	}if(abs(s1[2]-s2[2])==1){
		cout<<"1111";
	}else{
		cout<<"1110";
	}
	return 0;
}
