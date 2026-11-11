#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pll pair<ll,ll>
#define fi first
#define se second 
int check(char c){
	if(c=='A'||c=='B'||c=='C')return 0;
	else return 1;
}
int check2(char c1,char c2){
	if(c1=='A'&&c2=='B')return 1;
	if(c1=='C'&&c2=='B')return 1;
	if(c1=='D'&&c2=='F')return 1;
	if(c1=='B'&&c2=='A')return 1;
	if(c1=='B'&&c2=='C')return 1;
	if(c1=='F'&&c2=='D')return 1;
	return 0;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)cout<<1;
	else cout<<0;
	string t1,t2;
	t1=s1.substr(0,2);
	t2=s2.substr(0,2);
	if((c1==c2)&&t1==t2)cout<<1;
	else cout<<0;
	if((c1==c2)&&(t1==t2)&&(check(s1[2])==check(s2[2])))cout<<1;
	else cout<<0;
	if((c1==c2)&&(t1==t2)&&(check(s1[2])==check(s2[2]))){
		if(check2(s1[2],s2[2]))cout<<1;
		else cout<<0;
	}
	else cout<<0;
}
