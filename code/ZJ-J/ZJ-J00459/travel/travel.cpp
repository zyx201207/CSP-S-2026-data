#include<bits/stdc++.h>
using namespace std;
using ll=long long;
string s1,s2,s3,s4;
int main(){
ios::sync_with_stdio(0);
cin.tie(0);cout.tie(0);
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
cin>>s1>>s2>>s3>>s4;
if(s1!=s3){
	cout<<"0000";
}
else{
	cout<<"1";
	if(s2.substr(0,2)!=s4.substr(0,2))cout<<"000";
	else{
		cout<<"1";
		bool is1=s2[2]-'A'>=3?1:0;
		bool is2=s4[2]-'A'>=3?1:0;
		if(is1!=is2)cout<<"00";
		else{
			cout<<"1";
			if(s2[2]-s4[2]<=1)cout<<"1";
			else cout<<"0";
		}
	}
}


return 0;
}
