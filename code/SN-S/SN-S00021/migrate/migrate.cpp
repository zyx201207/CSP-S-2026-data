#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll MAXN=2e6+10;
ll n,m,c,t,Ans;
ll a[MAXN],l[MAXN],r[MAXN],onlyl[MAXN],onlyr[MAXN];
ll ans[MAXN],ztl[MAXN],ztr[MAXN];
ll read(){
	char x;
	ll f=1,d=0;
	x=getchar();
	while(x<'0'||x>'9'){
		if(x=='-')f=-1;
		x=getchar();
	}
	while(x>='0'&&x<='9'){
		d=d*10+(x-'0');
		x=getchar();
	}
	return d*f;
}
ll checkl(int x){
	if(ztl[x])return onlyl[x];
	ztl[x]=1;
	ll a=l[x]-l[x+1]+1;
	for(int i=x-l[x];i<x+1-l[x+1]&&i<n;i++){
		a+=checkl(i);
	}
	return onlyl[x]=a;
}
ll checkr(int x){
	if(ztr[x])return onlyr[x];
	ztr[x]=1;
	ll a=r[x]-r[x-1]+1;
	for(int i=r[x-1]+x;i<x+r[x]+x&&i<=n;i++){
		a+=checkr(i);
	}
	return onlyr[x]=a;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read();
	for(t=read();t>0;t--){
		memset(a,0,sizeof(a));
		memset(l,0,sizeof(l));
		memset(r,0,sizeof(r));
		memset(ans,0,sizeof(ans));
		Ans=0;
		n=read(),m=read();
		for(int i=1;i<=n;i++){
			a[i]=read();
		}
		ll L=0,R=0;
		for(int i=1;i<n;i++){
			if(R+i>=n)R=n-i-1;
			while(R+i+1<=n&&a[R+i+1]-a[i]<=m){
				R++;
			}
			r[i]=R;
			R--;
		}
		for(int i=n;i>0;i--){
			if(i-L<=0)L=i-1;
			while(a[i]-a[i-L-1]<=m&&i-L-1>0){
				L++;
			}
			l[i]=L;
			L--;
		}
		for(int i=1;i<=n;i++){
			printf("%lld %lld\n",l[i],r[i]);
		}
		for(int i=2;i<n;i++){
			Ans+=(checkr(i)-1)*(checkl(i+1)-1);
		}
		printf("%lld\n",Ans);
	}
	return 0;
}
