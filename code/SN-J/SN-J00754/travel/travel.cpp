//SN-J000754 余炜杰 西安辅轮中学 
#include<bits/stdc++.h>
//#define int long long int
using namespace std;

signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)cout<<1;//同一节车厢
	else {
		cout<<"0000";//不在同一车厢，后面全不成立 
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]) cout<<1;//同一排 
	else{
		cout<<"000";//不在同一排，后面全不成立 
		return 0;
	}
	bool flags1=0,flags2=0;
	if(s1[2]=='D'||s1[2]=='E') flags1=1;//在D或E，flag就为1，否则为0，在ABC 
	if(s2[2]=='D'||s2[2]=='E') flags2=1;
	if(flags1==flags2)cout<<1;//同一侧 
	else {
		cout<<"00";//不在过道同一侧，就不相邻 
		return 0;
	}
	if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='D'&&s2[2]=='E'))cout<<1;//一坨 
	else cout<<0; 
	return 0;
}
