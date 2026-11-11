#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e8;
void fc(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
}
signed main(){
	fc();
	string a1,a2,b1,b2;
	cin>>a1>>a2>>b1>>b2;
	if(a1==b1) cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	string i=a2.substr(0,2);
	string j=b2.substr(0,2);
	if(i==j) cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	char k=a2[2];
	char l=b2[2];
	if(k=='F'){
		if(l=='D') cout<<1;
		else cout<<0;
	}
	else if(k!='D'){
		if(l=='C'||l=='B'||l=='A') cout<<1;
		else cout<<0;
	}
	if(k=='A'){
		if(l!='B') cout<<0;
		else cout<<1;
	}
	if(k=='B'){
		if(l!='A'||l!='C') cout<<0;
		else cout<<1;
	}
	if(k=='C'){
		if(l!='B') cout<<0;
		else cout<<1;
	}
	if(k=='D'){
		if(l!='F') cout<<0;
		else cout<<1;
	}
	if(k=='F'){
		if(l!='D') cout<<0;
		else cout<<1;
	}
	return 0;
}

