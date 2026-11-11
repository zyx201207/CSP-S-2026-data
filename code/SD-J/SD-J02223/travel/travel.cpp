#include<bits/stdc++.h>
using namespace std;
int x,y,n,m;
char st1,st2;
string s,t;
bool check1(char x,char y){
	if((x=='A'||x=='B'||x=='C')&&(y!='D'&&y!='E')) return 1;
	if((x=='D'||x=='E')&&(y!='A'&&y!='B'&&y!='C')) return 1;
	return 0;
}
bool check2(char x,char y){
	if(x=='A'&&y=='B') return 1;
	if(x=='B'&&y=='C') return 1;
	if(x=='D'&&y=='E') return 1;
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>x>>s>>y>>t;
	cout<<((x==y)?1:0);
	if(x!=y){
		cout<<"000";
		return 0;
	}
	for(int i=0;i<2;i++) n=n*10+s[i]-'0';
	for(int i=0;i<2;i++) m=m*10+t[i]-'0';
	cout<<((n==m)?1:0);
	st1=s[2];
	st2=t[2];
	cout<<((n==m&&check1(st1,st2))?1:0);
	cout<<((n==m&&check2(st1,st2))?1:0);
	return 0;
}
//Trick||Treat!
