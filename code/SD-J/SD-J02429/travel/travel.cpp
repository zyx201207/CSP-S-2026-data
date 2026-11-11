#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string x,y,s,t;
	int a,b,c,d;
	cin>>x>>s>>y>>t;
	for(int i=0;i<=1;i++){
		if(x[i]!=y[i]){
			cout<<"0000";
			return 0;
		}
	}
	for(int i=0;i<=1;i++){
		if(s[i]!=t[i]){
			cout<<"1000";
			return 0;
		}
	}
	if(s[2]=='A') a=1;
	else if(s[2]=='B') a=2;
	else if(s[2]=='C') a=3;
	else if(s[2]=='D') a=5;
	else a=6;
	if(t[2]=='A') b=1;
	else if(t[2]=='B') b=2;
	else if(t[2]=='C') b=3;
	else if(t[2]=='D') b=5;
	else b=6;
	c=max(a,b);
	d=min(a,b);
	if(c-d==1) cout<<"1111";
	else if(c==3&&d==1) cout<<"1110";
	else cout<<"1100";
	return 0;
} 
