#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)cout<<1;
	else cout<<0;
	string x,y;
	x+=s1[0],x+=s1[1],y+=s2[0],y+=s2[1];
	if(x==y&&c1==c2){
		cout<<1;
	}
	else cout<<0;
	if(((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D'))&&x==y&&c1==c2){
		cout<<1;
	}
	else cout<<0;
	if(c1==c2&&x==y&&((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='A')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D'))){
		cout<<1;
	}
	else cout<<0;
	return 0;
} 
