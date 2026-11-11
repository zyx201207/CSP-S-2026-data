#include<bits/stdc++.h>
using namespace std;
int pd(string s1,string s2,int sum,int num){
	if(s1[2]=='A'&&s2[2]=='B'&&num==0&&sum==0) cout<<1;
	else if(s1[2]=='B'&&s2[2]=='A'&&num==0&&sum==0) cout<<1;
	else if(s1[2]=='B'&&s2[2]=='C'&&num==0&&sum==0) cout<<1;
	else if(s1[2]=='C'&&s2[2]=='B'&&num==0&&sum==0) cout<<1;
	else if(s1[2]=='D'&&s2[2]=='F'&&num==0&&sum==0) cout<<1;
	else if(s1[2]=='F'&&s2[2]=='D'&&num==0&&sum==0) cout<<1;
	else  cout<<0;	
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	long long a,b,ans=0,ans1=999,sum=0,num=0;
	string s1,s2;
	cin>>a>>s1>>b>>s2;
	if(a==b) cout<<1;
	if(a!=b){
		num=1;
		cout<<0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]&&num==0) cout<<1;
	if(s1[0]!=s2[0]||s1[1]!=s2[1]||num==1){
		sum=1;
		cout<<0;
	}
	if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C') ans=1;
	if(s1[2]=='D'||s1[2]=='F') ans=2;
	if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C') ans1=1;
	if(s2[2]=='D'||s2[2]=='F') ans1=2;
	if(ans==ans1&&sum==0&&num==0) cout<<1;
	if(ans!=ans1||sum==1||num==1) cout<<0;
	pd(s1,s2,sum,num);
	return 0;
}
