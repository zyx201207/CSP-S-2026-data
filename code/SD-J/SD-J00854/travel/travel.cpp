#include<bits/stdc++.h>
using namespace std;
string s1,s2,c1,c2;
map<char,int> mp;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	int cnt1=0,cnt2=0;
	cnt1=(s1[0]-'0')*10+(s1[1]-'0');
	cnt2=(s2[0]-'0')*10+(s2[1]-'0'); 
	int f=1;
	//1
	if(c1==c2) cout<<1;
	else f=0;
	if(!f)cout<<0;
	//2
	f=1;
	if(c1==c2){
		if(cnt1==cnt2) cout<<1;
		else f=0;
	}else f=0;
	if(!f)cout<<0;
	//3
	f=1;
	mp['A']=1;
	mp['B']=1;
	mp['C']=1;
	mp['D']=0;
	mp['F']=0;
	if(c1==c2){
		if(cnt1==cnt2){
			if(mp[s1[2]]==mp[s2[2]]) cout<<1;
			else f=0;
		}
		else f=0;
	}else f=0;
	if(!f)cout<<0;
	//4
	f=1;
	int x=s1[2]-s2[2];
	x=abs(x);
	if(c1==c2){
		if(cnt1==cnt2){
			if(mp[s1[2]]==mp[s2[2]]){
				if(x==1) cout<<1;
				else f=0;
			}
			else f=0;
		}
		else f=0;
	}else f=0;
	if(!f)cout<<0;
	return 0;
} //Trick||Treat!
