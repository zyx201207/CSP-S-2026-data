#include<bits/stdc++.h>
using namespace std;
int a,b,amm,bnn;
char m[5],n[5],mp,np;
int main(){//一定删注释，x1y1x2y2是个欸
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>a>>m>>b>>n;
	if(a!=b){
		cout<<"0000";
		return 0;
	}
	cout<<1;
	amm=10*(m[0]-'0')+m[1]-'0';mp=m[2];
	bnn=10*(n[0]-'0')+n[1]-'0';np=n[2];
	if(amm!=bnn){
		cout<<"000";
		return 0;
	}
	cout<<1;
	if(mp=='A' || mp=='B' || mp=='C'){
		if(np=='A' || np=='B' || np=='C'){
			cout<<1;
		}else{
			cout<<"00";
			return 0;
		}
	}else if(mp=='D' || mp=='F'){
		if(np=='D' || np=='F'){
			cout<<1;
		}else{
			cout<<"00";
			return 0;
		}
	}
	if((mp=='A' && np=='B') || (mp=='C' && np=='B') || (mp=='D' && np=='F')){
		cout<<1;
	}else if((np=='A' && mp=='B') || (np=='C' && mp=='B') || (np=='D' && mp=='F')){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}

