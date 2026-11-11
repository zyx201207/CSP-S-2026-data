#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll read(){
	ll f=1,x=0,c=getchar();
	while(!isdigit(c)){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
const int N=2e6+7;
ll c,t;
ll n,d,x[N],f[N],mx[N];
void solve1(){
	if(d<=x[2]-x[1])printf("0\n");
	else printf("%lld\n",max(0ll,n-(2*(d/(x[2]-x[1]))-1)));
}
void dfs(int step,int now){
	if(now>n)return;
	if(mx[now]>step){
		mx[now]=step;
		f[now]=1;
	}else if(mx[now]==step){
		++f[now];
	}
	ll l=lower_bound(x+1,x+1+n,x[now]+1)-x,r=lower_bound(x+1,x+1+n,x[now]+d)-x;
	if(x[l]-x[now]>d)return;
//	cout<<now<<' '<<l<<' '<<r<<endl;
	for(ll i=l;i<=r;i++){
		dfs(step+1,i);
	}
}
void solve2(){
	ll res=0;
	for(ll i=1;i<=n;i++){
		memset(mx,0x3f,sizeof mx);
		memset(f,0,sizeof f);
		dfs(0,i);
//		cout<<f[4]<<' '<<mx[4]<<endl;
		for(ll j=1;j<=n;j++)res+=f[j]==2;
	}
	printf("%lld\n",res);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),t=read();
	while(t--){
		n=read(),d=read();
		for(ll i=1;i<=n;i++)x[i]=read();
		if(n==1){
			printf("%lld\n",0);
		}
		else if(c==11||c==12)solve1(); 
		else solve2();
	}
	return 0;
}

