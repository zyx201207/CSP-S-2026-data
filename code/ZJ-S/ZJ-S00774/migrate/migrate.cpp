#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll C,T,n,h,a[2000010],ans;
vector<ll> v[2000010];
ll d[2000010],b[2000010];
bool vis[2000010];
ll read(){
	ll f=1,cnt=0;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		cnt=cnt*10+ch-'0';
		ch=getchar();
	}
	return f*cnt;
}
struct data{
	ll to,jl;
	bool operator > ( const data& a ) const { return jl > a.jl; }
};
void dj(ll s){
	memset(vis,0,sizeof(vis));
	memset(d,0x7f,sizeof(d));
	memset(b,0,sizeof(b));
	d[s]=0;
	b[s]=1;
	priority_queue<data,vector<data>,greater<data> > q;
	q.push({s,0});
	while(!q.empty()){
		ll from=q.top().to;
		q.pop();
		if(vis[from]) continue;
		vis[from]=1;
		for(ll i=0;i<v[from].size();i++){
			ll to=v[from][i];
			if(d[to]>d[from]+1){
				d[to]=d[from]+1;
				b[to]=b[from];
				q.push({to,d[to]});
			}
			else if(d[to]==d[from]+1){
				b[to]+=b[from];
			}
		}
	}
	for(ll i=s+1;i<=n;i++){
		if(b[i]==2){
//			cout<<s<<' '<<i<<'\n';
			ans++;
		}
	}
	return;
}
void build(ll x,ll y){
	v[x].push_back(y);
	v[y].push_back(x);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>C>>T;
	while(T--){
		n=read(),h=read();
		ans=0;
		for(ll i=1;i<=n;i++) a[i]=read(),v[i].clear();
		for(ll i=1;i<=n;i++){
			for(ll j=i+1;j<=n;j++){
				if(a[j]-a[i]<=h) build(i,j);
				else break;
			}
		}
		for(ll i=1;i<=n;i++){
			dj(i);
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
*/
