#include<bits/stdc++.h>
using namespace std;
#define int long long
string s1,s2,s3,s4;
map<int,int> mp;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	mp['A']=1,mp['B']=1,mp['C']=1,mp['D']=2,mp['F']=2;
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3){
		cout<<1;
		if(s2[0]==s4[0]&&s2[1]==s4[1]){
			cout<<1;
			if(mp[s2[2]]==mp[s4[2]]){
				cout<<1;
				if((s2[2]=='A'&&s4[2]=='C')||(s2[2]=='C'&&s4[2]=='A')) cout<<0;
				else cout<<1;
			}else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
	
	
	return 0;
}
/*
³æÐè
ÔÆÁ¦
°×É×
³æÇÒ 
*/ 
