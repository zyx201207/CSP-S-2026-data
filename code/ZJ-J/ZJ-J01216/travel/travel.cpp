#include<bits/stdc++.h>
using namespace std;
#define ll long long
string c,s,cc,ss;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>s>>cc>>ss;
	if(c==cc){
		cout<<1;
	}
	else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	string r="",rr="";
	r+=s[0],rr+=ss[0];
	r+=s[1],rr+=ss[1];
	if(r==rr){
		cout<<1;
	}
	else{
		cout<<0<<0<<0;
		return 0;
	}
	char st1=s[2],st2=ss[2];
	if((st1<='C'&&st1>='A'&&st2<='C'&&st2>='A')||(st1<='F'&&st1>='D'&&st2<='F'&&st2>='D')){
		cout<<1;
	}
	else{
		cout<<0<<0;
		return 0;
	}
	if((st1==st2+1||st1==st2-1)||((st1=='D'&&st2=='F')||(st1=='F'&&st2=='D'))){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}