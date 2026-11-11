#include<bits/stdc++.h>
#define N 200009
using namespace std;
typedef long long ll;

inline ll read(){
	ll x=0;bool sym=0;char ch=getchar();
	while(!isdigit(ch)) sym^=(ch=='-'),ch=getchar();
	while(isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return sym?-x:x;
}

ll c,t,n,d,ans,res,x[N],dst[N];
bool vst[N];
vector<bool> to[N];
queue<ll> q;

/*ll bfs(ll u,ll aim){
	while(!q.empty()) q.pop();
	memset(vst,0,sizeof vst);
	vst[u]=1,dst[u]=0;
	q.push(u);
	while(!q.empty()){
		ll uu=q.front();q.pop();
		for(ll i=0;i<to[uu].size();i++){
			ll v=to[uu][i];
			if(vst[v]) continue;
			vst[v]=1,dst[v]=dst[uu]+1;
			q.push(v);
		}
	}
	return dst[aim];
}
void bfs1(ll u,ll aim,ll step,ll &res){
	while(!q.empty()) q.pop();
	q.push(u);
	while(!q.empty()&&step>=1){
		ll uu=q.front();q.pop();
		for(ll i=0;i<to[uu].size();i++){
			ll v=to[uu][i];
			q.push(v);
		}
		step--;
	}
	while(!q.empty()){
		ll uu=q.front();q.pop();
		if(uu==aim) res++;
	}
}
bool check(ll a,ll b){
	vst[a]=1;
	ll len=bfs(a,b);
	res=0;
	bfs1(a,b,len,res);
	if(res==2) return 1;
	return 0;
}*/

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);

	c=read(),t=read();
	while(t--){
		ans=0;
		n=read(),d=read();
		for(ll i=1;i<=n;i++) x[i]=read();
		for(ll i=1;i<n;i++) for(ll j=i+1;j<=n;j++){
			//if(x[j]-x[i]<=d) to[i].push_back(j);
			ll mx=d/(x[2]-x[1]);
			if(mx==0) continue;
			ll br=(j-i)/mx;
			if(br==1&&(j-i)%mx==mx-1) ans++;
		}
		//for(ll i=1;i<n;i++) for(ll j=i+1;j<=n;j++) ans+=check(i,j);
		cout<<ans<<'\n';
	}

	return 0;
}
