#include<bits/stdc++.h>
#define int long long
using namespace std;
string s1,s2,s3,s4;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	if(s1!=s3){
		cout<<"0000";
	}else if(s2[0]!=s4[0]||s2[1]!=s4[1]){
		cout<<"1000";
	}else if((s2[2]>'C'&&s4[2]<='C')||(s4[2]>'C'&&s2[2]<='C')){
		cout<<"1100";
	}else if(abs(s2[2]-s4[2])!=1){
		cout<<"1110";
	}else{
		cout<<"1111";
	}
	return 0;
}

