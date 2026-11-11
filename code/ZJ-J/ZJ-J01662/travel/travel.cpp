#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
	int cnt1;
	int cnt2;
	if(s1==s3) cout<<1;
	else cout<<0;
	if(s1==s3&&s2[0]==s4[0]&&s2[1]==s4[1]) cout<<1;
	else cout<<0;
	if(s2[2]=='A') cnt1=1;
	if(s2[2]=='B') cnt1=2;
	if(s2[2]=='C') cnt1=3;
	if(s2[2]=='D') cnt1=4;
	if(s2[2]=='F') cnt1=5;
	
	if(s4[2]=='A') cnt2=1;
	if(s4[2]=='B') cnt2=2;
	if(s4[2]=='C') cnt2=3;
	if(s4[2]=='D') cnt2=4;
	if(s4[2]=='F') cnt2=5;
	
	if(s1==s3&&s2[0]==s4[0]&&s2[1]==s4[1]){
		if(cnt1<=3&&cnt2<=3) cout<<1;
		else if(cnt1>3&&cnt2>3) cout<<1;
		else cout<<0;
	}
	else cout<<0;
	if(s1==s3&&(abs(cnt1-cnt2)==1&&s2[0]==s4[0]&&s2[1]==s4[1])){
		if(cnt1<=3&&cnt2<=3) cout<<1;
		else if(cnt1>3&&cnt2>3) cout<<1;
		else cout<<0;
	}
	else cout<<0;
	return 0;
}
