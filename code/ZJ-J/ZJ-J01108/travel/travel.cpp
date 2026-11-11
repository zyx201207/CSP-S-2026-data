#include <bits/stdc++.h>
using namespace std;
#define int long long
int fl;
string s1,s2,c1,c2,ss1,ss2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	fl=0;
	if(c1==c2) cout<<1,fl=1;
	else cout<<0;
	if(fl){
		ss1="";ss2="";
		ss1+=s1[0];
		ss1+=s1[1];
		ss2+=s2[0];
		ss2+=s2[1];
		if(ss1==ss2) cout<<1;
		else cout<<0,fl=0;
	}
	else cout<<0;
	if(fl){
		if((s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C')||(s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F')){
			cout<<1;
		}
		else cout<<0,fl=0;
	}
	else cout<<0;
	if(fl){
		if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='B'&&s2[2]=='A')||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')){
			cout<<1;
		}
		else cout<<0;
	}
	else cout<<0;
}
