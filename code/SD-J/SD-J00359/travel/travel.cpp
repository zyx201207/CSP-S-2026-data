#include<bits/stdc++.h>
#define ll long long 
using namespace std;
string s1,s2,s3,s4,ans;
inline bool check1(string a,string b){
	if((a[2]=='A'||a[2]=='B'||a[2]=='C')&&(b[2]=='A'||b[2]=='B'||b[2]=='C')) return true;
	if((a[2]=='D'||a[2]=='F')&&(b[2]=='D'||b[2]=='F')) return true;
	return false;
}
inline bool check2(string a,string b){
	if((a[2]=='A'&&b[2]=='B')||(a[2]=='B'&&b[2]=='A')) return true;
	if((a[2]=='B'&&b[2]=='C')||(a[2]=='C'&&b[2]=='B')) return true;
	if((a[2]=='D'&&b[2]=='F')||(a[2]=='F'&&b[2]=='D')) return true;
	return false;
}
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3) ans=ans+'1';
	else ans=ans+'0';
	if(s2[0]==s4[0]&&s2[1]==s4[1]&&s1==s3) ans=ans+'1';
	else ans=ans+'0';
	if(s2[0]==s4[0]&&s2[1]==s4[1]&&s1==s3&&check1(s2,s4)) ans=ans+'1';
	else ans=ans+'0';
	if(s2[0]==s4[0]&&s2[1]==s4[1]&&s1==s3&&check1(s2,s4)&&check2(s2,s4)) ans=ans+'1';
	else ans=ans+'0';
	cout<<ans;
	return 0;
} 
