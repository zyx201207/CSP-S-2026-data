#include<bits/stdc++.h>
using namespace std;
string ans;
bool solve(string c,string cc){
	if(c.size()!=cc.size()){
		return 0;
	}
	for(int i=0;i<c.size();i++){
		if(c[i]!=cc[i]) return 0;
	}
	return 1;
}
bool solve1(string s,string ss){
	for(int i=0;i<s.size()-1;i++){
		if(s[i]!=ss[i]) return 0;
	}
	return 1;
}
bool solve2(string s,string ss){
	for(int i=0;i<s.size()-1;i++){
		if(s[i]!=ss[i]) return 0;
	}
	if((s[2]>='A'&&s[2]<='C'&&ss[2]>='A'&&ss[2]<='C')||(s[2]>='D'&&s[2]<='F'&&ss[2]>='D'&&ss[2]<='F')){
		return 1;
	}
	return 0;
}
bool solve3(string s,string ss){
	if((s[2]=='A'&&ss[2]=='B')||(ss[2]=='A'&&s[2]=='B')||(s[2]=='B'&&ss[2]=='C')||(ss[2]=='B'&&s[2]=='C')||(s[2]=='D'&&ss[2]=='F')||(s[2]=='F'&&ss[2]=='D')){
		return 1;
	}
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	bool ok=1;
	string c,s,cc,ss;
	cin>>c>>s>>cc>>ss;
	ans.clear();
	if(solve(c,cc)){
		ans+='1';
	}
	else{
		ok=0;
		ans+='0';
	}
	if(solve1(s,ss)&&ok==1){
		ans+='1';
	}
	else{
		ok=0;
		ans+='0';
	}
	if(solve2(s,ss)&&ok==1){
		ans+='1';
	}
	else{
		ok=0;
		ans+='0';
	}
	if(solve3(s,ss)&&ok==1){
		ans+='1';
	}
	else{
		ok=0;
		ans+='0';
	}
	cout<<ans;
	return 0;
}
