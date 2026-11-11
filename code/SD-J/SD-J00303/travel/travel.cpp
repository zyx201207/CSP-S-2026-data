#include<bits/stdc++.h>
#define int long long
using namespace std;
string c1,s1,c2,s2,ans;
map<char,int> q;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	q['A']=1,q['B']=2,q['C']=3,q['D']=99,q['F']=100;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		ans+='1';
	}else{
		ans+='0';
	}
	if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]){
		ans+='1'; 
	}else{
		ans+='0';
	}
	if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]&&( (s1[2]=='F'&&s2[2]=='D')||(s1[2]=='D'&&s2[2]=='F')||(s1[2]!='F'&&s2[2]!='D'&&s1[2]!='D'&&s2[2]!='F') )){
		ans+='1';
	}else{
		ans+='0';
	}
	if(ans[2]=='1'&&abs(q[s1[2]]-q[s2[2]])<=1){
		ans+='1';
	}else{
		ans+='0';
	}
	cout<<ans;
	return 0;
} 
