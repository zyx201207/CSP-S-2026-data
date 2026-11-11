#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string r1,r2,s1,s2;
	bool f1=0,f2=0;
	cin>>r1>>r2>>s1>>s2;
	if(r1==s1){
		cout<<1;
		f2=1;
	}else cout<<0;
	if(f2==1&&r2[0]==s2[0]&&r2[1]==s2[1]){
		cout<<1;
		f1=1;
	}else cout<<0;
	if(f2==1&&f1==1&&((r2[2]=='A'||r2[2]=='B'||r2[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'))||((r2[2]=='D'||r2[2]=='F')&&(s2[2]=='D'||s2[2]=='F'))&&r2!=s2){
		cout<<1;
	}else cout<<0;
	if(f2==1&&f1==1&&((r2[2]=='A'&&s2[2]=='B')||(r2[2]=='B'&&s2[2]=='A')||(r2[2]=='B'&&s2[2]=='C')||(r2[2]=='C'&&s2[2]=='B')||(r2[2]=='D'&&s2[2]=='F')||(r2[2]=='F'&&s2[2]=='D'))&&r2!=s2){
		cout<<1;
	}else cout<<0;
	return 0;
} 
