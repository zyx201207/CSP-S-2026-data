#include<bits/stdc++.h>
#define int long long
using namespace std;
string a1,a2,b1,b2;
int turn(string s){
	int sum=0;
	for(int i=s.size()-1;i>=0;i--){
		sum*=10;
		sum+=s[i]-'0';
	}
	return sum;
}
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>a1>>a2>>b1>>b2;
	if(turn(a1)==turn(b1))cout<<1;
	else{cout<<0<<0<<0<<0;return 0;}
	if(a2[0]==b2[0]&&a2[1]==b2[1])cout<<1;
	else{cout<<0<<0<<0;return 0;}
	if((a2[2]<='C'&&b2[2]<='C')||(a2[2]>='D'&&b2[2]>='D'))cout<<1;
	else{cout<<0<<0;return 0;}
	if(((abs(a2[2]-b2[2])==1)&&(a2[2]!='C'||b2[2]!='C'))||((a2[2]=='D'&&b2[2]=='F')||(a2[2]=='F'&&b2[2]=='D')))cout<<1;
	else{cout<<0;return 0;}
	return 0;
}
