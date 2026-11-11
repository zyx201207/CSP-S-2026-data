#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
int c1,c2;
string s1,s2,ans="";
map<char,int>mp;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	mp['A']=mp['B']=mp['C']=1;
	mp['D']=mp['F']=2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)ans+='1';
	else {
		ans+="0000";
		cout<<ans;
		return 0;
	}
	int t1=(s1[0]-48)*10+(s1[1]-48),t2=(s2[0]-48)*10+(s2[1]-48);
	if(t1==t2)ans+='1';
	else {
		ans+="000";
		cout<<ans;
		return 0;
	}
	char w1=s1[2],w2=s2[2];
	if(mp[w1]==mp[w2]){
		ans+='1';
	}else{
		ans+="00";
		cout<<ans;
		return 0;
	}
	if(w1=='B'||w1=='D'||w1=='F'){
		ans+='1';
	}
	else if(w2=='B'||w2=='D'||w2=='F'){
		ans+='1';
	}
	else ans+='0';
	cout<<ans;
	return 0;
}
