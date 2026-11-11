#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=3e6+5;
ll C,n,d,T,a[N],ARIS[N],KEI[N],fl[N],cnt[N]; 
ll ql[N],qr[N],tot,tott,aris[N],kei[N];
bool check(ll ARIS,ll KEI){
	return ((KEI-ARIS)<=d);
}
struct node{
	ll e,d,f,g;
}c[N];
int main(){
	freopen("migrate.in","r",stdin); 
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>C>>T;
	if(C==11||C==12){
		while(T--){
			tot=0;
			tott=0;
			cin>>n>>d;
			for(ll i=1;i<=n;i++){
				cin>>a[i];
			}
			if(a[2]-a[1]>d){
				cout<<"0\n";
				continue;
			}
			cout<<max(0LL,n-(d/(a[2]-a[1])*2)+1)<<'\n';
		}	
		return 0;
	}
	while(T--){
		tot=0;
		tott=0;
		cin>>n>>d;
		for(ll i=1;i<=n;i++){
			cin>>a[i];
		}
		a[0]=0x3f3f3f3f3f3f3f3f;
		a[n+1]=0x3f3f3f3f3f3f3f3f;
		for(ll i=1;i<=n;i++){
			ARIS[i]=lower_bound(a+1,a+1+n,a[i]-d)-a;
			KEI[i]=upper_bound(a+1,a+1+n,a[i]+d)-a-1;
	//		cout<<ARIS[i]<<' '<<KEI[i]<<'\n';
		}
	//	cout<<"\n\n";
		ll las=1;
		for(ll i=2;i<=n+1;i++){
			if(!check(a[i-1],a[i])){
				ql[++tot]=las;
				qr[tot]=i-1;
				cnt[tot]=0;
				las=i;
		//		cout<<"neko"<<ql[tot]<<' '<<qr[tot]<<'\n';
			}
		}
		ll nowl=0,nowr=0,op=0,ans=0;
		for(ll i=1;i<=n;i++){
			ll l=0,r=0;
			if(i!=1){
				l=max(ARIS[i],ARIS[i-1]);
				r=min(KEI[i],KEI[i-1]);
	//			cout<<"AAA "<<l<<' '<<r<<'\n';
			}	
			if(l==i-1||r==i){
			//	cout<<i<<'\n';
				continue;
			}
			if(ARIS[i+1]==l||KEI[max(0LL,i-2)]==r){
			//	cout<<i<<'\n';
				continue;
			}
			if(qr[op]<r){
				while(qr[op]<r){
					op++;
				}	
				nowl=ql[op];
			}cnt[op]++;
	//		cout<<"A "<<ql[op]<<' '<<qr[op]<<' '<<l<<' '<<r<<'\n';
		}
		nowl=0,nowr=0,op=0,ans=0;
		for(ll i=1;i<=n;i++){
			ll l=0,r=0;
			if(i!=1){
				l=max(ARIS[i],ARIS[i-1]);
				r=min(KEI[i],KEI[i-1]);
	//			cout<<l<<' '<<r<<'\n';
			}	
			if(l==i-1||r==i){
				continue;
			}
			if(ARIS[i+1]==l||KEI[max(0LL,i-2)]==r){
				continue;
			}
			if(qr[op]<r){
				while(qr[op]<r){
					op++;
				}	
				nowl=ql[op];
			}
			c[++tott].f=i-1;
			c[tott].g=i;
			c[tott].d=nowl;
			while(ARIS[c[tott].g+1]<i-1){
				c[tott].g++;
			}
			while(KEI[c[tott].f-1]>i){
				c[tott].f--;
			}
			nowl=i-1;
	//		cout<<"A "<<ql[op]<<' '<<qr[op]<<' '<<cnt[op]<<' '<<l<<' '<<r<<'\n';
		}
		op=tot;
		ll tottt=tott;
		nowr=n;
		for(ll i=n;i>=1;i--){
			ll l=0,r=0;
			if(i!=1){
				l=max(ARIS[i],ARIS[i-1]);
				r=min(KEI[i],KEI[i-1]);
	//			cout<<l<<' '<<r<<'\n';
			}	
			if(l==i-1||r==i){
				continue;
			}
			if(ARIS[i+1]==l||KEI[max(0LL,i-2)]==r){
				continue;
			}
	//		cout<<"D "<<l<<' '<<ql[op]<<' '<<nowr<<'\n';
			if(ql[op]>l){
				while(ql[op]>l){
					op--;
				}
				nowr=qr[op];	
			}
	//		cout<<"E "<<l<<' '<<ql[op]<<' '<<nowr<<'\n';
			c[tottt--].e=nowr;
			nowr=i;
	//		cout<<"C "<<tottt+1<<' '<<nowr<<"\n";
		}
		ans=0;
		for(ll i=1;i<=tott;i++){
		//	cout<<c[i].d<<' '<<c[i].e<<' '<<c[i].f<<' '<<c[i].g<<'\n';
		/*	if((c[i].f-c[i].d)*(c[i].e-c[i].g)<0){
				continue;
			}*/
	//		cout<<c[i].d<<' '<<c[i].e<<' '<<c[i].f<<' '<<c[i].g<<'\n';
			ans+=(c[i].f-c[i].d)*(c[i].e-c[i].g);
		}
		cout<<ans<<"\n";
	}
	return 0;
}/*
再见了，王女 
*/
