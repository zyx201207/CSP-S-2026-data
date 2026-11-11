#include<bits/stdc++.h>
#define ll long long
#define pli pair<ll,int>
#define F first
#define S second
using namespace std;
const int M=5e5+5,N=505,Q=1e5+5;
int c,n,m,d,q,w[M],hd[M+N],tt;
struct no{
	int to,nx,w;
}b[M*2];
void add(int x,int y,int z){
	b[++tt].nx=hd[x];
	b[hd[x]=tt].to=y;
	b[tt].w=z;
}
ll as[N][Q*2],s;
int rk[M],ct;
pair<int,int>qr[Q];
ll ds[M+N];
void dij(int t){
	priority_queue<pli,vector<pli>,greater<pli> >q;
	memset(ds,0x3f,sizeof(ds)); 
	bool v[M+N]={0};
	q.push({ds[t]=0,t});
	while(!q.empty()){
		int x=q.top().S;
		q.pop();
		if(v[x]){
			continue;
		}
		v[x]=1;
		for(int i=hd[x],y,z;i;i=b[i].nx){
			y=b[i].to;
			z=b[i].w;
			if(!v[y]&&ds[x]+z<ds[y]){
				q.push({ds[y]=ds[x]+z,y});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1,k,a,t;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a>>t;
			add(i,a+n,t);
			add(a+n,i,t);
		}
	}
	for(int i=1,x,y;i<=q;i++){
		cin>>x>>y;
		qr[i]={x,y};
		rk[x]=++ct;
		rk[y]=++ct;
	}
	for(int i=1;i<=n;i++){
		dij(i);
		for(int j=1,x,y;j<=q;j++){
			x=qr[j].F;
			y=qr[j].S;
			as[i][rk[x]]=ds[x+n];
			as[i][rk[y]]=ds[y+n];
		}
	}
	for(int i=1,x,y;i<=q;i++){
		x=qr[i].F;
		y=qr[i].S;
		s=2e18;
		for(int j=1;j<=n;j++){
			s=min(s,as[j][rk[x]]+as[j][rk[y]]);
		}
		cout<<s+w[x]+w[y]<<"\n";
	}
	return 0;
}