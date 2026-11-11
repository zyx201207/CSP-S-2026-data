#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e6+10;

template<typename T> void chkmax(T &x,T y) {if(y>x) x=y;}
template<typename T> void chkmin(T &x,T y) {if(y<x) x=y;}

int c;
int n,l[N],r[N];
ll d,x[N],ans;

ll dis[N],f[N],pre[N];

struct node{
	int u;
	ll w;
	
	friend bool operator < (node x,node y){
		return x.w>y.w; 
	}
	
};

void dij(int k){
	for(int i=1;i<=n;i++){
		dis[i]=LLONG_MAX;
		f[i]=0; 
	}
	
	priority_queue<node>q; 
	q.push({k,0});
	dis[k]=0;
	f[k]=1;
	
	while(!q.empty()){
		int u=q.top().u;
		q.pop();
		for(int i=l[u];i<=r[u];i++){
			if(abs(x[i]-x[u])>d||i==k) continue;
			if(dis[i]>dis[u]+1){
				dis[i]=dis[u]+1;
				f[i]=f[u]; 
				if(f[i]<=3) q.push({i,dis[i]});
			} 
			else if(dis[i]==dis[u]+1){
				f[i]+=f[u];
			}  
		}
	}
	
}


void solve(){
	
	ans=0;
	
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>x[i];
	
	for(int i=1;i<=n;i++){
		l[i]=lower_bound(x+1,x+1+n,x[i]-d)-x;
		r[i]=upper_bound(x+1,x+1+n,x[i]+d)-x-1;
	}
	
	if(c<=10){
		for(int u=1;u<=n;u++){
//			cout<<u<<'\n';
			dij(u);
			for(int v=u+1;v<=n;v++){
				if(f[v]==2) ans++;
			}
			
			for(int i=1;i<=n;i++){
//				if(i<u) cout<<0<<' ';
//				else cout<<f[i]<<' ';
			}
//			cout<<'\n';
		}
		
		cout<<ans<<'\n';
	}
	else if(c<=12){
		dij(1);
		for(int i=1;i<=n;i++){
			if(f[i]==2) pre[i]++;
		}
		for(int i=1;i<=n;i++) pre[i]+=pre[i-1];
		for(int i=1;i<=n;i++) ans+=pre[i]; 
		cout<<ans<<'\n';
	}
	else cout<<ans<<'\n'; 
	
	
	
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	int t;
	cin>>c>>t;
	while(t--) solve();	
	
	return 0;
}

