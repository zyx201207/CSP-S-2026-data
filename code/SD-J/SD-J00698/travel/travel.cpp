#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int ca,cb;
	string za,zb;cin>>ca>>za>>cb>>zb;
	if(ca!=cb) {
		cout<<"0000";
		return 0;
	}else cout<<1;
	int a=0,b=0,cnt=0;
	while(za[cnt]>='0'&&za[cnt]<='9'){
		a*=10,a+=(za[cnt++]-'0');
	}
	cnt=0;
	while(zb[cnt]>='0'&&zb[cnt]<='9'){
		b*=10,b+=zb[cnt++]-'0';
	}
	
	if(a==b)cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	if((za[2]>='D'&&za[2]>='D')||(za[2]<'D'&&zb[2]<'D')){
		cout<<1;
	}else {
		cout<<"00";
		return 0;
	}
	if(abs(za[2]-zb[2])<=1) cout<<1;
	else cout<<0;
	return 0;
}

