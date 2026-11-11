//friendship is magic!!! 



#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll c,n,m,d,q;
ll w[500005],b[500005];
struct node{
//	ll id,w;
	ll to,next,w;
}a[500005];
ll adj[500005],id;
//vector<vector<node> > a;
void add(ll aa,ll bb,ll cc){
	id++;
	a[id].to=bb;
	a[id].next=adj[aa];
	adj[aa]=id;
	a[id].w=cc;
}
ll f[500005];
ll dfs(ll k,ll kk){
	memset(f,0x3f,sizeof(f));
	queue<ll> q;
	q.push(k);
	f[k]=0;
	while(q.size()){
		ll x=q.front();
		q.pop();
		for(int i=adj[x];i;i=a[i].next){
			if(f[x]+a[i].w>=f[a[i].to]){
				continue;
			}
			q.push(a[i].to);
			f[a[i].to]=f[x]+a[i].w;
		}
	}
	return f[kk];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++){
		ll o;
		scanf("%lld",&o);
		ll x,t,xx,tt;
		scanf("%lld%lld",&x,&t);
		for(int j=2;j<=o;j++){
			scanf("%lld%lld",&xx,&tt);
//			node y,yy;
//			y.id=xx,y.w=t+tt;
//			yy.id=x,y.w=t+tt;
//			a[x].push(y);
//			a[xx].push(yy);
			add(x,xx,t+tt);
			add(xx,x,t+tt);
			x=xx,t=tt;
		}
	}
	for(int i=1;i<=q;i++){
		ll x,y;
		scanf("%lld%lld",&x,&y);
		ll ans=dfs(x,y);
		ans=ans+w[x]+w[y];
		printf("%lld\n",ans);
	}
	return 0;
}
/*#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll c,n,m,d,q;
ll w[500005],b[500005][22][2],a[505][505];
/*struct node{
//	ll id,w;
	ll to,next,w;
}a[500005];
ll adj[500005],id;
//vector<vector<node> > a;
void add(ll aa,ll bb,ll cc){
	id++;
	a[id].to=bb;
	a[id].next=adj[aa];
	adj[aa]=id;
	a[id].w=cc;
}
ll f[5000];
ll dfs(ll k,ll kk){
	memset(f,0x3f,sizeof(f));
	queue<ll> q;
	for(int i=1;i<=b[k][0][0];i++){
		ll kkk=b[k][i][0];
		q.push(kkk);
		f[kkk]=0;
	}
	while(q.size()){
		ll x=q.front();
		q.pop();
		for(int i=1;i<=500;i++){
			if(a[x][i]==-1){
				continue;
			}
			if(f[x]+a[x][i]>=f[i]){
				continue;
			}
			q.push(i);
			f[i]=f[x]+a[x][i];
		}
	}
	ll all=1e18;
	for(int i=1;i<=b[kk][0][0];i++){
		all=min(all,b[kk][i][0]);
	}
	return all;
}
int main(){
	//freopen("subway.in","r",stdin);
	//freopen("subway.out","w",stdout);
	cout<<"1  "<<endl<<" "<<endl;
	cin>>c>>n>>m>>d>>q;
	memset(f,-1,sizeof(f));
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++){
		ll o;
		scanf("%lld",&o);
		ll oo[500005];
		for(int j=1;j<=o;j++){
			ll x,y;
			scanf("%lld%lld",&x,&y);
			oo[j]=x;
			b[x][0][0]++;
			ll idd=b[x][0][0];
			b[x][idd][0]=i;
			b[x][idd][1]=y;
			if(idd>1){
				for(int k=1;k<idd;k++){
					a[i][b[x][k][0]]=min(a[i][idd],b[x][k][1]+b[x][idd][1]);
					a[i][idd]=min(a[i][b[x][k][0]],b[x][k][1]+b[x][idd][1]);
				}
			}
		}
	}
	for(int i=1;i<=q;i++){
		ll x,y;
		scanf("%lld%lld",&x,&y);
		ll all=dfs(x,y);
		all+=w[x]+w[y];
		printf("%lld\n",all);
	}
	return 0;
}*/

