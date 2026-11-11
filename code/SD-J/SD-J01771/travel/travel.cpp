#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s,s1,c,c1;
	cin>>s>>s1>>c>>c1;
	if(s==c){
		cout<<1;
	} 
	else{
		cout<<0;
	} 
	if(s==c&&s1[0]==c1[0]&&s1[1]==c1[1]){
		cout<<1;
	} 
	else{
		cout<<0;
	} 
	if(s==c&&s1[0]==c1[0]&&s1[1]==c1[1]&&(s1[2]>='A'&&s1[2]<='C'&&c1[2]>='A'&&c1[2]<='C'||(s1[2]>='D'&&s1[2]<='F'&&c1[2]>='D'&&c1[2]<='F'))){
		cout<<1;
	} 
	else{
		cout<<0;
	} 
	if((s==c&&s1[0]==c1[0]&&s1[1]==c1[1]&&(s1[2]>='A'&&s1[2]<='C'&&c1[2]>='A'&&c1[2]<='C')&&(s1[2]=='A'&&c1[2]=='B'||s1[2]=='B'&&c1[2]=='A'||s1[2]=='B'&&c1[2]=='C'||s1[2]=='C'&&c1[2]=='B')||(s1[2]>='D'&&s1[2]<='F'&&c1[2]>='D'&&c1[2]<='F'||s1[2]=='D'&&c1[2]=='F'||s1[2]=='F'&&c1[2]=='D'))){
		cout<<1;
	} 
	else{
		cout<<0;
	} 
	return 0;
} 
