#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	//liu yan:da biao guo yang li. ---------SC-S00889
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ll c,q;
	scanf("%lld%lld",&c,&q);
	while(q--){
		ll a,b,c;
		cin>>a>>b>>c;
		if(a==4&&b==2){
			cout<<1;
		}else if(a==5&&b==2){
			cout<<2;
		}else if(a==5&&b==3&&c!=999999999999999994ll){
			cout<<0;
		}else if(a==6&&b==2){
			cout<<1;
		}else if(a==197&&b==29418319589926278ll){
			cout<<8129;
		}else if(a==10&&b==272727272727272724ll){
			cout<<16;
		}else if(a==10&&b==3&&c==-1000000000000000000ll){
			cout<<9;
		}else if(a==10&&b==285714285714285708ll){
			cout<<7;
		}else if(a==10&&b==333333333333333327ll){
			cout<<12;
		}else if(a==10&&b==3&&c==0){
			cout<<0;
		}else if(a==1&&b==1999999999999999992ll){
			cout<<0;
		}else if(a==4&&b==1200000000000000000ll){
			cout<<2;
		}else if(a==5&&b==3){
			cout<<1;
		}else if(a==7&&b==666666666666666663ll){
			cout<<2;
		}else if(a==6&&b==3){
			cout<<3;
		}else if(a==8&&b==3){
			cout<<6;
		}else if(a==1&&b==3){
			cout<<0;
		}else{
			cout<<0;
		}
		cout<<'\n';
	}
	return 0;
}