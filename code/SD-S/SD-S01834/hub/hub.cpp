#include<bits/stdc++.h>
#define int long long
#define deb(a) cerr<<#a<<"="<<(a)<<endl 
using namespace std;

const int maxn=2e6+10;//, msk_fail=-1e9;

int n,k;

basic_string<int>G[maxn];

struct sta{
	int cnt,dis;//if >0. min dis, to a key-point
	//if <0. max dis, s.t. dis-to-outtree must <=
	
	//if = msk_fail. then fail.
};
int H;//H means max dis allow

sta ad_son(sta u,sta v){
//	if(u.dis==msk_fail||v.dis==msk_fail)return{0,msk_fail};
	if(u.dis>=0){
		if(v.dis>=0){
			return{u.cnt+v.cnt,min(u.dis,v.dis+1)};
		}else{
			if(u.dis+1<=-v.dis)return{u.cnt+v.cnt,u.dis};
			else if(-v.dis-1>0)return{u.cnt+v.cnt,v.dis+1};
			else return{maxn,0};
		}
	}else{
		if(v.dis>=0){
			if(v.dis+1<=-u.dis){
//			assert(v.dis+1<=H);	
			return{u.cnt+v.cnt,v.dis+1};
			}
			else return{u.cnt+v.cnt,u.dis};
		}else{
			if(-v.dis-1>0)return{u.cnt+v.cnt,max(u.dis,v.dis+1)};
			else return{maxn,0};
		}
	}
}


using node=array<array<array<sta,2>,3>,2>;

node f[maxn];//u-sel; conc; is-ok

void cmin(sta&a,sta b){
	if(a.cnt>b.cnt||(a.cnt==b.cnt&&(
		b.dis>=0?(a.dis<0||a.dis>b.dis):(a.dis<0&&a.dis>b.dis)
	)))a=b;
}

void dfs(int u,int fa){
	for(int j:{0,1,2})
		f[u][0][j][0]={0,-H},
		f[u][0][j][1]={maxn,0},
		f[u][1][j][0]={1,0},
		f[u][1][j][1]={1,0};

	for(int v:G[u])if(v!=fa){
		node nf;
		for(int i:{0,1})for(int j:{0,1,2})for(int o:{0,1})nf[i][j][o]={maxn,0};
		
		dfs(v,u);
		
		for(int us:{0,1})for(int uc:{0,1,2})for(int uo:{0,1})
		for(int vs:{0,1})for(int vc:{0,1,2})
			if(uc+vc+(!us&&vs)<=2)
				for(int vo:{0,1}){
					auto cr=ad_son(f[u][us][uc][uo],f[v][vs][vc][vo]);
					
//					if(u==1&&v==2)deb(u),deb(us),deb(uc),deb(uo),deb(v),deb(vs),deb(vc),deb(vo);
					
					cmin(nf[us][uc+vc+(!us&&vs)][cr.dis>=0], cr);
				}
	
//		if(u==1&&v==2){
//			
//		auto cr=ad_son(f[u][0][0][0],f[v][1][0][1]);
//		deb(cr.dis),deb(cr.cnt);
//
//		}
		
		f[u]=nf;
		
//		if(u==1){
//			deb(v),deb(f[v][1][0][1].cnt);
//			deb(v),deb(f[v][1][0][1].dis);
//			deb(f[1][0][1][1].cnt);
//			deb(f[1][0][1][1].dis);
//		}
		
//		for(int i:{0,1})for(int j:{0,1,2})assert(f[u][i][j].dis<=H);
	}
	
//	deb(u);
//	for(int i:{0,1})for(int j:{0,1,2})for(int o:{0,1})if(f[u][i][j][o].cnt<maxn){
//		deb(i),deb(j),deb(o),deb(f[u][i][j][o].cnt),deb(f[u][i][j][o].dis); 
//	}
//	
}

int CAS;

void sol(){
	cin>>n>>k;
	for(int i=1;i<=n;++i)G[i]={};
	for(int i=1,u,v;i<n;++i){
		cin>>u>>v;
		G[u]+=v,G[v]+=u;
	}
	
	if(k==n){
		cout<<"0\n";return;
//		cout<<++CAS<<" "<<"0\n";return;
	}
	
//	H=2;dfs(1,0);
//	deb(f[1][0][2][1].cnt),deb(f[1][0][2][1].dis);
//	
//	deb(f[2][1][0][1].dis),deb(f[2][1][0][1].cnt);
//	deb(f[5][0][1][1].dis),deb(f[5][0][1][1].cnt);
//	deb(f[9][0][0][0].dis),deb(f[9][0][0][0].cnt);
//	
//	
//	exit(0);
	
	int l=1,r=n;
	while(l<r){
		int md=((l+r)>>1);
		H=md;
		dfs(1,0);
//		if(f[1][0][2].cnt+(f[1]))
		if(min(f[1][0][2][1].cnt,f[1][1][1][1].cnt) <= k)
			r=md;
		else l=md+1;
	}
	cout<<r<<'\n';
//	cout<<++CAS<<" "<<r<<'\n';
}

signed main(){

//	freopen("a.in","r",stdin);

	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	int c,T;cin>>c>>T;
	while(T--)sol();
}
