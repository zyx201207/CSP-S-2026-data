#include<bits/stdc++.h>
#define int(N) 3e5+5
#define ll long long 
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	ll a1,a2,b1,b2,m;	
	char s1,s2;	
	cin>>a1>>a2>>s1;	
	cin>>b1>>b2>>s2;
	//cout<<a1<<' '<<a2<<' '<<s1; 
	if(a1==b1){
		cout<<1;
	}
	else cout<<0;
	if(a1==b1&&a2==b2){
		cout<<1;
	}
	else cout<<0;
	if(a1==b1&&a2==b2&&((s1>='A'&&s1<='C'&&s2>='A'&&s2<='C')||((s1=='D'||s1=='F')&&(s2=='D'||s2=='F')))){
		cout<<1;
	}
	else cout<<0;
	ll f=0;
	if(a1==b1&&a2==b2&&((s1>='A'&&s1<='C'&&s2>='A'&&s2<='C')||((s1='D'||s1<='F')&&(s2=='D'||s2=='F')))){
		if(s1=='A'){
			if(s2=='B'){
				f=1;
			}
		}
		if(s1=='B'){
			if(s2=='A'||s2=='C'){
				f=1;
			}
		}
		if(s1=='C'){
			if(s2=='B'){
				f=1;
			}
		}
		if(s1=='D'){
			if(s2=='F'){
				f=1;
			}
		}
		if(s1=='F'){
			if(s2=='D'){
				f=1;
			}
		}
	}
	if(f==1){
		cout<<1;
	}
	else cout<<0;
	return 0;
}

