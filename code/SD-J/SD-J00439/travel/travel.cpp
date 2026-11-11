#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	string s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
	if(s1!=s3){
		cout<<"0000";
	}else if(s2[0]!=s4[0]||s2[1]!=s4[1]){
		cout<<"1000";
	}else{
		cout<<11;
		if((s2[2]=='C'&&s4[2]=='D')||(s2[2]=='D'&&s4[2]=='C')){
			cout<<0;
		}else{
			cout<<1;
		}
		if((s2[2]+1==s4[2]||s2[2]==s4[2]+1)&&(s2[2]!='D'&&s4[2]!='C')&&(s2[2]!='C'&&s4[2]!='D')){
			cout<<1;
		}else{
			cout<<0;
		}
	}
	return 0;
}
