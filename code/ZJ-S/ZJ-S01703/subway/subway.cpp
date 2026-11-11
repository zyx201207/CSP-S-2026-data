#include <bits/stdc++.h>
#define int long long
#define N 501005
#define MN 505
#define pb push_back
using namespace std;
int c,n,m,q,d,w[N],dis[N],tim[N],vis[N],ans[N],g,kd[MN][MN];
struct node{
	int v,w;
};
struct query{
	int st,ed,id;
}qes[N];
bool cmp(query l,query r){
	return l.st<r.st;
}
struct nd{
	int u,d;
	bool operator <(const nd &x)const{
		return d>x.d;
	}
};
vector<int>a[MN],t[MN],me[N];
vector<node>ve[N];
void dij(int st,int idx){
	priority_queue<nd>q;
	q.push({st,0});
	dis[st]=0;
	while(q.size()){
		nd tmp=q.top();
		q.pop();
		int u=tmp.u;
		if(vis[u]==idx)continue;
		vis[u]=idx;
		for(auto i:ve[u]){
			int v=i.v,w=i.w;
			
			if(tim[v]!=idx||dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				tim[v]=idx;
				q.push({v,dis[v]});
			}
		}
	}
}

void sv_1(){
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=0;j<k;j++){
			int aa,tt;
			cin>>aa>>tt;
			a[i].pb(aa);
			t[i].pb(tt);
			ve[aa].pb((node){m+i,tt});
			ve[m+i].pb((node){aa,tt});
		}
	}
	
	for(int i=1;i<=q;i++){
		int st,ed;
		cin>>st>>ed;
		if(ed<st)swap(ed,st);
		qes[i]=(query){st,ed,i};
	}
	sort(qes+1,qes+q+1,cmp);
	for(int i=1;i<=q;){
		int j=i;
		dij(qes[j].st,i);
		while(qes[i].st==qes[j].st){
			
			ans[qes[i].id]=dis[qes[i].ed]+w[qes[i].st]+w[qes[i].ed];
			i++;
		}
	}
	for(int i=1;i<=q;i++){
		cout<<ans[i]<<"\n";
	}
	
}
void sv_2(){
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=0;j<k;j++){
			int aa,tt;
			cin>>aa>>tt;
			g=tt;
			a[i].pb(aa);
			me[aa].pb(i);
		}
	}
	memset(kd,0x3f,sizeof kd);
	for(int i=1;i<=m;i++){
		for(auto j:me[i]){
			for(auto k:me[i]){
				kd[k][j]=kd[j][k]=1;
			}
		}
	}
	for(int i=1;i<=n;i++){
		kd[i][i]=0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				kd[j][k]=min(kd[j][k],kd[j][i]+kd[i][k]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		int st,ed;
		cin>>st>>ed;
		if(ed<st)swap(ed,st);
		int ans=0x3f3f3f3f;
		for(auto j:me[ed]){
			for(auto k:me[st]){
				ans=min(ans,kd[j][k]);
			}
		}
		cout<<(ans+1)*2*g+w[qes[i].st]+w[qes[i].ed]<<"\n";
	}
}
signed main(){
	freopen("subway.in","r",stdin);
freopen("subway.out","w",stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cin>>c;
	cin>>n>>m>>d>>q;
	if(c<=11){
		sv_1();
	}else if (c<=19){
		sv_2();
	}
	return 0;
}
	
	
	
	