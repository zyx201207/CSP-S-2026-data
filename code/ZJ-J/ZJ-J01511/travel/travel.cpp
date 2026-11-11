#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool a1,a2,a3,a4;
bool f(int k){
	char x=s1[2],y=s2[2];
	if(k==1){
		return abs(x-y)==1;
	}
	bool q=false,e=false;
	if(x=='A'||x=='B'||x=='C') q=true;
	if(y=='A'||y=='B'||x=='C') q=true;
	if(x=='D'||x=='E') e=true;
	if(y=='D'||y=='E') e=true;
	return q!=e;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		a1=true;
	}
	if(a1==true&&s1[0]==s2[0]&&s1[1]==s2[1]){
		a2=true;
	}
	if(a2==true&&f(0)){
		a3=true;
	}
	if(a3==true&&f(1)){
		a4=true;
	}
	if(a1==true) cout<<1;
	else cout<<0;
	if(a2==true) cout<<1;
	else cout<<0;
	if(a3==true) cout<<1;
	else cout<<0;
	if(a4==true) cout<<1;
	else cout<<0;
	return 0;
}