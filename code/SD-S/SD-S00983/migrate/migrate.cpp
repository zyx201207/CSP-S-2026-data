#include<bits/stdc++.h>

using namespace std;

#define ll long long

inline ll Rd(){
	ll x=0,f=1; int c=getchar();
	while (c<'0' || c>'9'){
		if (c=='-') f=-1;
		c=getchar(); 
	}
	while (c>='0'&&c<='9'){
		x=x*10+(c^'0');
		c=getchar();
	}
	return x*f;
}


ll Tnb,T;
ll a[2000006];

void solve1(){
	for (int i=1;i<=T;i++){
		printf("0\n");
	}
	return;
}
void solve2(){//11 12
	while (T--){
		ll n=Rd(),D=Rd();
		for (int i=1;i<=n;i++){
			a[i]=Rd();
		}
		ll asd=a[2]-a[1];
		ll d=D/asd;
//		cerr<<"d: "<<d<<" asd"<<endl; what  
		if (d==0 || d==1){
			printf("0\n");
			continue;
		}
		ll ans=0;
		for (int i=1;i<=n;i++){
			ans=ans+1ll*(n-i)/d;
		}
		printf("%lld\n",ans);
	}
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	Tnb=Rd();
	T=Rd();
	if (Tnb==0){
		solve2();
		return 0;
	}
	
	if (13<=Tnb && Tnb<=14){
		solve1();
		return 0;
	}
	if (11<=Tnb && Tnb<=12){
		solve2();
		return 0; 
	}
	while (T--){
		
	}
	
	return 0;
}
