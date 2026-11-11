#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
char s1,s2,s3,s4,s5,s6,k1,k2,k3;
int c1,c2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>s3>>s4>>c2>>s2>>s5>>s6;
	if(c1==c2)cout<<1;
	else cout<<0;
	if(c1==c2&&s1==s2&&s3==s5)cout<<1;
	else cout<<0;
	if(c1==c2&&s1==s2&&s3==s5){
		if(s4=='A'&&s6=='B'||s4=='A'&&s6=='C'||s4=='B'&&s6=='A'||s4=='B'&&s6=='C'||s4=='C'&&s6=='A'||s4=='C'&&s6=='B')cout<<1;
		else if(s4=='D'&&s6=='F'||s4=='F'&&s6=='D')cout<<1;
		else cout<<0;
	}
	else cout<<0;
	if(c1==c2&&s1==s2&&s3==s5){
		if(s4=='D'&&s6=='F'||s4=='F'&&s6=='D'||s4=='A'&&s6=='B'||s4=='A'&&s6=='C'||s4=='B'&&s6=='A'||s4=='B'&&s6=='C'||s4=='C'&&s6=='B')cout<<1;
		else cout<<0;
	}
	else cout<<0;
	return 0;
}