#include<bits/stdc++.h>
using namespace std;
#define gc() getchar()
//using ll=long long;
using ll=int;
void rd(ll&x){
	x=0;ll f=1;char c=gc();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=gc();}
	while(c>='0'&&c<='9'){c&=15;x=x*10+c;c=gc();}
	x*=f;
}
//using ul=unsigned long long;
constexpr ll N=2000006;
struct E{
	ll a,t;
};
ll cc,t,k,n,m,u,v,d[N],c[N];
vector<ll>e[N];
void df1(ll f,ll b,ll de){
	d[f]=min(d[f],de);
	if(de>d[0]){d[0]=de;u=f;}
	for(ll&i:e[f])if(i!=b){df1(i,f,de+1);}
}
void df2(ll f,ll b,ll de){
	d[f]=min(d[f],de);
	if(de>d[0]){d[0]=de;v=f;}
	for(ll&i:e[f])if(i!=b){df2(i,f,de+1);}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	rd(cc);rd(t);
while(t--){
	rd(n);rd(k);
	for(ll i=0;i<=n;++i){d[i]=0x3f3f3f3f;c[i]=0;e[i].clear();}
	for(ll i=1;i<n;++i){rd(u);rd(v);e[u].push_back(v);e[v].push_back(u);}
	d[0]=0;
	df1(1,0,1);
	d[0]=0;
	df2(u,0,1);
	m=n;
	for(ll i=1;i<=n;++i){c[d[i]]++;}
	for(ll i=0;i<=n;++i){
		m-=c[i];m-=1;//-mid
		if(m<=k){
			printf("%d\n",i);//! int !
			break;
		}
	}
}
	return 0;
}
