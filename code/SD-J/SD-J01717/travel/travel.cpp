#include<bits/stdc++.h>
#define int long long
using namespace std;
string c1,s1,c2,s2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	string t1=s1.substr(0,2);
	string t2=s2.substr(0,2);
	char ch1=s1[2];
	char ch2=s2[2];
	if(c1==c2) cout<<1;
	else cout<<0;
	if(c1==c2){
		if(t1==t2) cout<<1;
		else cout<<0;
	}else{
		cout<<0;
	}
	if(c1==c2&&t1==t2){
		if((('A'<=ch1&&ch1<='C')&&('A'<=ch2&&ch2<='C'))||(('D'<=ch1&&ch1<='F')&&('D'<=ch2&&ch2<='F'))){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		cout<<0;
	}
	if(c1==c2&&t1==t2&&(('A'<=ch1&&ch1<='C')&&('A'<=ch2&&ch2<='C'))||(('D'<=ch1&&ch1<='F')&&('D'<=ch2&&ch2<='F'))){
		if(ch1=='A'&&ch2=='B') cout<<1;
		else if(ch1=='B'&&ch2=='C') cout<<1;
		else if(ch1=='B'&&ch2=='A') cout<<1;
		else if(ch1=='C'&&ch2=='B') cout<<1;
		else if(ch1=='D'&&ch2=='F') cout<<1;
		else if(ch1=='F'&&ch2=='D') cout<<1;
		else cout<<0;
	}else{
		cout<<0;
	}
	return 0;
}
