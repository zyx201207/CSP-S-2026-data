#include <bits/stdc++.h>
using namespace std;
string s1,s2,e1,e2;
unordered_map<char,int>mp;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>e1>>e2;
	mp['A']=1;mp['B']=1;mp['C']=1;mp['D']=2;mp['F']=2;
	if(s1==e1){
		cout<<1;
		if(s2[0]==e2[0]&&s2[1]==e2[1]){
			cout<<1;
			char ch1=s2[2],ch2=e2[2];
			if(ch2<ch1) swap(ch1,ch2);
			if(mp[ch1]==mp[ch2]){
				cout<<1;
				if((ch1=='A'&&ch2=='B')||(ch1=='B'&&ch2=='C')||(ch1=='D'&&ch2=='F')) cout<<1;
				else cout<<0;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
