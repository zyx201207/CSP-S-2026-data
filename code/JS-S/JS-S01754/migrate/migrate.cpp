//18:00
#include <bits/stdc++.h>
#define ll long long
#define F(i,l,r) for(ll i=l;i<=r;i++)
using namespace std;const ll A=2e6+5;
ll rd(){char c=getchar();ll x=0,f=1;while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c))x=x*10+c-'0',c=getchar();return x*f;}
/*ll n,m,a[A],f;
void get(ll l,ll r){
	if(r-l<2)return;
	cout<<l<<' '<<r<<"\t";F(i,l,r)cout<<a[i]<<" \n"[i==r];
	vector<ll> v;
	F(i,l,r-2)if(a[i]+a[i+1]<=m&&a[i+1]+a[i+2]<=m&&a[i]+a[i+1]+a[i+2]>m)v.push_back(i);
	ll z=v.size();
	cout<<"\t"<<z<<"   ";for(ll x:v)cout<<x<<" ";cout<<"\n";
	if(!z)return;
	if(z==1){f+=(v[0]-l+1)*(r-v[0]-1);return;}
	f+=(v[0]-l+1)*(v[1]-v[0]);
	F(i,1,z-2)f+=(v[i]-v[i-1])*(v[i+1]-v[i]);
	f+=(v[z-1]-v[z-2])*(r-v[z-1]-1);
}
void sov(){
	n=rd(),m=rd(),f=0;
	F(i,1,n)a[i]=rd();for(ll i=n;i;i--)a[i]-=a[i-1];
	ll l=2;
	F(i,2,n)if(a[i]>m)get(l,i-1),l=i+1;
	get(l,n);
	printf("%lld\n",f);
}*/
ll a[A],f[A],g[A],l[A],r[A],cL[A],cR[A];
void sov(){
	ll n=rd(),m=rd(),ans=0;
	F(i,1,n)a[i]=rd(),f[i]=g[i]=l[i]=r[i]=cL[i]=cR[i]=0;
	ll p=1;F(i,1,n){while(p<=n&&a[p]-a[i]<=m)p++;r[i]=p-1;}
	p=n;for(ll i=n;i;i--){while(p&&a[i]-a[p]<=m)p--;l[i]=p+1;}
	F(i,1,n)cL[l[i]]++,cR[r[i]]++;
	F(i,1,n)f[i]=(r[l[i]]==i?f[l[i]]+cR[i]:cR[i]+1);
	for(ll i=n;i;i--)g[i]=(l[r[i]]==i?g[r[i]]+cL[i]:cL[i]+1);
/*	F(i,1,n)cout<<f[i]<<" \n"[i==n];
	F(i,1,n)cout<<g[i]<<" \n"[i==n];*/
//	F(i,1,n)if(l[r[i]]!=i||l[r[i]-1]!=i/*||r[i]-i<=1*/)f[i]=0;
//	F(i,1,n)if(r[l[i]]!=i||r[l[i]+1]!=i/*||i-l[i]<=1*/)g[i]=0;
/*	F(i,1,n)cout<<l[i]<<" \n"[i==n];
	F(i,1,n)cout<<r[i]<<" \n"[i==n];
	F(i,1,n)cout<<f[i]<<" \n"[i==n];
	F(i,1,n)cout<<g[i]<<" \n"[i==n];*/
//	F(i,1,n)g[i]+=g[i-1];
	F(i,2,n-2)if(l[i]==l[i+1]&&r[i]==r[i+1]&&l[i]<i&&r[i]>i+1){
		ans+=(f[l[i]]+cR[i+1]-1)*(g[r[i]]+cL[i]-1);
//		cout<<i<<' '<<ans<<"\n";
	}
/*	ll u=1,v=1;
	F(i,1,n){
		while(u<=n&&l[u]<r[i]-1)u++;
		while(v<=n&&l[v]<r[i])v++;
		ans+=f[i]*(g[v-1]-g[u-1]);
		cout<<u<<' '<<v<<" "<<ans<<"\n";
	}*/
	printf("%lld\n",ans);
}
int main(){
	freopen("migrate.in","r",stdin);freopen("migrate.out","w",stdout);
	ll c=rd(),t=rd();F(i,1,t)sov();return 0;
}
