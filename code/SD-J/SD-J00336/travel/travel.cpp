#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	int a1,a2,b1,b2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<1;
	else {
		cout<<0<<0<<0<<0;
		return 0;
	}
	a1=(s1[0]-'0')*10+(s1[1]-'0');
	a2=(s2[0]-'0')*10+(s2[1]-'0');
	if(c1==c2&&a1==a2) cout<<1;
	else cout<<0;
	if((a1==a2)&&(s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')){
		cout<<1;
	}
	else if((a1==a2)&&(s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F')){
		cout<<1;
	}
	else {
		cout<<0<<0;
		return 0;
	}
	if((s1[2]=='A'&&s2[2]=='B')||(s2[2]=='A'&&s1[2]=='B')){
		cout<<1;
	}
	else if((s1[2]=='B'&&s2[2]=='C')||(s2[2]=='B'&&s1[2]=='C')){
		cout<<1;
	}
	else if((s1[2]=='D'&&s2[2]=='F')||(s2[2]=='D'&&s1[2]=='F')){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}
//I will AFO on CSP-2026
//goodbye my OI dream QWQ TT
//luogu id tuotuoyl(别看) 
//祝我whk加油  11:48 别炸
