#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,c;
	string b,d;
	cin>>a;
	cin>>b;
	cin>>c;
	cin>>d;
	if(a==c) cout<<1;
	else{
		cout<<0<<0<<0<<0;
		return 0;
	} 
	if(b[0]+b[1]==d[0]+d[1]) cout<<1;
	else{
		cout<<0<<0<<0;
		return 0;
	}
	if((b[2]=='A' || b[2]=='B' || b[2]=='C') && (d[2]=='A' || d[2]=='B' || d[2]=='C') || (b[2]=='D' || b[2]=='F') && (d[2]=='F' || d[2]=='D')){
		cout<<1;
	}
	else{
		cout<<0<<0;
		return 0;
	}
	if(b[2]+1==d[2] || b[2]-1==d[2]) cout<<1;
	else cout<<0;
	return 0;
} 
