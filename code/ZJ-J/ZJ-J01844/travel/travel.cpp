#include<bits/stdc++.h>
using namespace std;
#define int long long
int c1,c2;
string s1,s2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<1;
	else cout<<0;
	int p1=(s1[0]-'0')*10+s1[1]-'0',p2=(s2[0]-'0')*10+s2[1]-'0';
	char w1=s1[2],w2=s2[2];
	if(c1==c2&&p1==p2) cout<<1;
	else cout<<0;
	if(c1==c2&&p1==p2&&((w1=='A'&&w2=='B')||(w1=='A'&&w2=='C')||(w1=='B'&&w2=='C')||(w1=='B'&&w2=='A')||(w1=='C'&&w2=='A')||(w1=='C'&&w2=='B')||(w1=='D'&&w2=='F')||(w1=='F'&&w2=='D'))) cout<<1;
	else cout<<0;
	if(c1==c2&&p1==p2&&((w1=='A'&&w2=='B')||(w1=='B'&&w2=='C')||(w1=='B'&&w2=='A')||(w1=='C'&&w2=='B')||(w1=='D'&&w2=='F')||(w1=='F'&&w2=='D'))) cout<<1;
	else cout<<0;
}