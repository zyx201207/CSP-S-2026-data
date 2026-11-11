#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
#define fi first
#define se second
#define eb emplace_back
int c,n,m,d,q,tn=1,cnt;
struct stopp{
	int k,t;
	unordered_map<int,int>x;
};

vector<stopp>b;
vector<vector<pii>>adj;
void addd(int u,int v,int w){
	if(adj.size()<max(u,v))adj.resize(max(u,v));
	adj[u].eb(v,w);
	adj[v].eb(u,w);
}
vector<array<int,3>>huan;
int maxu=-1;
array<int,3>maxa;
void add(int u,int v,int w){
	huan.eb(u,v,w);
	if(u>maxu){
		maxu=u;
		maxa[0]=u,maxa[1]=v,maxa[2]=w;
	}
	if(huan.size()>100){
		addd(maxa[0],maxa[1],maxa[2]);
		for(auto &x:huan){
			if(x[0]==maxa[0]&&x[1]==maxa[1]&&x[2]==maxa[2])continue;
			addd(x[0],x[1],x[2]);
		}
		huan.clear();
	}
}
vector<vector<int>>zdl;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	b.resize(m+5);
	for(int i=1;i<=m;i++){
		int w;
		cin>>w;
		add(tn,tn+1,w);
		b[i].k=tn+1;
		b[i].t=tn;
		tn+=2;
	}
	for(int i=1;i<=n;i++){
		int k,ai,t,lai;
		cin>>k;
		cin>>ai>>t;
		b[ai].x[k]=tn;
		add(b[ai].t,tn,t);
		tn+=2;
		lai=ai;
		for(int j=2;j<=k;j++){
			cin>>k;
			cin>>ai>>t;
			b[ai].x[k]=tn;
			add(b[ai].t,tn,t);
			add(b[lai].x[k],tn,0);
			tn+=3;
			lai=ai;
		}
	}
	addd(maxa[0],maxa[1],maxa[2]);
	for(auto &x:huan){
		if(x[0]==maxa[0]&&x[1]==maxa[1]&&x[2]==maxa[2])continue;
		addd(x[0],x[1],x[2]);
	}
	zdl.resize(tn+5,vector<int>(tn+5));
	for(int u=1;u<=tn;u++){
		for(pii vw:adj[u]){
			zdl[u][vw.first]=vw.se;
		}
	}
	for(int k=1;k<=tn;k++){
		for(int i=1;i<=tn;i++){
			for(int j=1;j<=tn;j++){
				zdl[i][j]=max(zdl[i][j],zdl[i][k]+zdl[k][j]);
			}
		}
	}
	int qx,qy;
	for(int i=1;i<=q;i++){
		cin>>qx>>qy;
		int u=b[qx].k,v=b[qy].k;
		cout<<zdl[u][v]<<endl;
	}
	return 0;
}

