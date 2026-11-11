#include<bits/stdc++.h>
using namespace std;
unordered_map<char,int> mp;
unordered_map<char,int> mp2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	mp['A']=1,mp['B']=1,mp['C']=1,mp['D']=2,mp['F']=2;
	mp2['A']=1,mp2['B']=2,mp2['C']=3,mp2['D']=4,mp2['F']=5;
	int a=0,b=0;
	char aw=s1[2],bw=s2[2];
	for(int i=0;i<s1.length();i++){
		if(s1[i]>='0'&&s1[i]<='9'){
			a=a*10+s1[i]-'0';
		}
	}
	for(int i=0;i<s2.length();i++){
		if(s2[i]>='0'&&s2[i]<='9'){
			b=b*10+s2[i]-'0';
		}
	}
	string s="";
	if(c1==c2){
		s+="1";
	}
	else{
		s+="0";
	}
	if(c1==c2&&a==b){
		s+="1";
	}
	else{
		s+="0";
	}
	if(c1==c2&&a==b&&mp[aw]==mp[bw]){
		s+="1";
	}
	else{
		s+="0";
	}
	if(c1==c2&&a==b&&mp[aw]==mp[bw]&&abs(mp2[aw]-mp2[bw])==1){
		s+="1";
	}
	else{
		s+="0";
	}
	cout<<s;
	return 0;
}
