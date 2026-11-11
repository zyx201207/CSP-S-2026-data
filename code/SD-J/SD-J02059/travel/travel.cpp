#include <bits/stdc++.h> 
#define int long long
#define endl "\n"
using namespace std;
int r,x;
string s1,s2;
int a,b,c,d; 
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>r>>s1>>x>>s2;
	if(r==x){
		a=1;
	}
	if(a==0){
		cout<<0<<0<<0<<0;
		return 0;
	}
	int r1=(s1[0]-'0')*10+(s1[1]-'0');
	int x1=(s2[0]-'0')*10+(s2[1]-'0');
	if(r1==x1){
		b=1;
	}
	if(b==0){
	cout<<"1000";
	return 0;	
	} 
	if((s1[2]!='D'&&s2[2]!='D'&&s1[2]!='F'&&s2[2]!='F')||(s1[2]!='A'&&s2[2]!='A'&&s1[2]!='B'&&s2[2]!='B'&&s1[2]!='C'&&s2[2]!='C')){
		c=1;
	}
	if(c==0){
		cout<<"1100";
		return 0;
	}
	if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='D'&&s2[2]=='F')||(s2[2]=='A'&&s1[2]=='B')||(s2[2]=='B'&&s1[2]=='C')||(s2[2]=='D'&&s1[2]=='F')) d=1;
	cout<<a<<b<<c<<d;
	return 0;
}
