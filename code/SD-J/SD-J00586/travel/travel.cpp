#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2;
	bool flag=true;
	int a,b;
	cin>>a>>s1>>b>>s2;
	string ans="";
	if(a==b&&flag){
		ans+='1';
	}else{
		ans+='0';
		flag=false;
	}
	if(flag&&s1[0]==s2[0]&&s1[1]==s2[1]){
		ans+='1';
	}else{
		ans+='0';
		flag=false;
	}
	if(flag&&((s1[2]=='D'&&s2[2]=='E'||s2[2]=='D'&&s1[2]=='E')||!(s1[2]=='D'||s2[2]=='E'||s2[2]=='D'||s1[2]=='E'))){
		ans+='1';
	}else ans+='0',flag=false;
	if(flag&&(s1[2]-1==s2[2]||s1[2]+1==s2[2])){
		cout<<ans<<1;
	}else {
		cout<<ans<<'0';
	}
	return 0;
}

