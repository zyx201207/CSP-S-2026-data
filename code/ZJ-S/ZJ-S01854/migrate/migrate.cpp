// 想要遗忘 这世界所有彷徨 也想过和海鸟去远方
// 即便不知道方向 也不知远方在何方
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

template<typename T>void chkmin(T &a,T b){ a=min(a,b); }
template<typename T>void chkmax(T &a,T b){ a=max(a,b); }
inline ll read(){ ll x; scanf("%lld",&x); return x; }


ll n,d,w[2000005],nxt[2000005];
const int M=8;
ll sta[M][3],sum[M],tab[1<<8],id;
ll a[3],b[3];

void press(ll *f){
	ll sum=0;
	for(ll i=0;i<3;i++){
		sum+=f[i];
		if(sum>3){
			ll d=sum-3;
			f[i]-=d,sum-=d;
		}
	}
}
void dfs(ll x,ll v){
	if(x){
		for(ll i=0;i<3;i++)b[i]=a[i];
		press(b);

		ll val=0;
		for(ll i=0;i<3;i++) val|=(b[i]<<(2*i));
		if(!tab[val]){
			tab[val]=++id;
			for(ll i=0;i<3;i++) sta[id][i]=b[i];
		}
	}
	if(x==3)return;
	for(ll i=v;i<=3;i++){
		a[x]=i;
		dfs(x+1,i);
		a[x]=0;
	}
}

pair<ll,ll> solve(ll x,ll y,ll bef){
	ll ret2=0,ret3=0;
	if(sum[bef]>=2){
		ll pos=0,sum=sta[bef][0];
		while(sum<2) sum+=sta[bef][++pos];
		ret2=max(0ll,nxt[x-pos]-x);
	}
	if(sum[bef]>=3){
		ll pos=0,sum=sta[bef][0];
		while(sum<3) sum+=sta[bef][++pos];
		ret3=max(0ll,nxt[x-pos]-x);
	}
	// cout<<"solving "<<x<<" "<<y<<": "<<sta[bef][0]<<" "<<sta[bef][1]<<" "<<sta[bef][2]<<endl;
	for(ll i=0;i<3&&y-i>x;i++){
		b[i]=0;
		for(ll j=0;j<3&&j<x;j++)
			b[i]+=(w[y-i]-w[x-j]<=d)*sta[bef][j];
	}
	press(b);
	// for(ll i=0;i<3;i++) cout<<b[i]<<" "; cout<<endl;
	ll val=0;
	for(ll i=0;i<3;i++) val|=(b[i]<<(2*i));
	// if(!tab[val]){
	// 	for(ll i=0;i<3;i++) cout<<b[i]<<" "; cout<<endl;
	// 	exit(0);
	// }
	assert(tab[val]);
	return {tab[val],ret2-ret3};
}

ll dp[2000005][M];

void procedure(){
	n=read(),d=read();
	for(ll i=1;i<=n;i++)w[i]=read();
	// cout<<"READ"<<endl;
	ll now=n;
	for(ll i=n;i>=1;i--){
		while(w[now]-w[i]>d)now--;
		nxt[i]=now;
	}
	ll ans=0;
	// for(ll i=1;i<=n;i++){
	// 	cout<<"making "<<i<<endl;
	// 	ll j=1,x=i,cnt=0;
	// 	while(nxt[x]!=x){
	// 		// ++cnt;
	// 		// if(cnt>100)exit(0);
	// 		ll y=nxt[x];
	// 		auto [A,B]=solve(x,y,j);
	// 		cout<<"move "<<x<<"->"<<y<<" add "<<B<<endl;	
	// 		j=A,ans+=B,x=y;
	// 	}
	// }
	for(ll x=1;x<=n;x++)
		for(ll j=1;j<=id;j++)dp[x][j]=0;
	for(ll x=1;x<=n;x++){
		dp[x][1]++;
		ll y=nxt[x];
		if(y!=x){
			for(ll j=1;j<=id;j++)if(dp[x][j]){
				auto [A,B]=solve(x,y,j);
				dp[y][A]+=dp[x][j];
				ans+=dp[x][j]*B;
			}
		}
	}
	printf("%lld\n",ans);
}
int main(){
	assert(freopen("migrate.in","r",stdin));
	assert(freopen("migrate.out","w",stdout));

	dfs(0,1);
	for(ll i=1;i<=id;i++){
		for(ll j=0;j<3;j++){
			// cout<<sta[i][j]<<" "; 
			sum[i]+=sta[i][j];
		}
		// cout<<endl;
	}
	int c=read(),T=read();
	while(T--) procedure();
}