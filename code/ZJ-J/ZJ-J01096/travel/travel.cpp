#include <bits/stdc++.h>
#define int long long
using namespace std;
int ans1,ans2,ans3,ans4;
char a1[101],a2[101],b1[101],b2[101],l,r;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1+1>>a2+1>>b1+1>>b2+1;
	ans1=(a1[1]-48)*10+(a1[2]-48);
	ans2=(b1[1]-48)*10+(b1[2]-48);
	if(ans1!=ans2){
		cout<<"0000";
		return 0;
	}
	ans3=(a2[1]-48)*10+(a2[2]-48);
	ans4=(b2[1]-48)*10+(b2[2]-48);
	if(ans3!=ans4){
		cout<<"1000";
		return 0;
	}
	l=a2[3];r=b2[3];
	if(l<='C'&&r>'C'){
		cout<<"1100";
		return 0;
	}
	if(l>'C'&&r<='C'){
		cout<<"1100";
		return 0;
	}
	if(l=='A'&&r=='B') cout<<"1111";
	else if(l=='B'&&r=='A') cout<<"1111";
	else if(l=='B'&&r=='C') cout<<"1111";
	else if(l=='C'&&r=='B') cout<<"1111";
	else if(l=='D'&&r=='F') cout<<"1111";
	else if(l=='F'&&r=='D') cout<<"1111";
	else cout<<"1110";
	return 0;
}
