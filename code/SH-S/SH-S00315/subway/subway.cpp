#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int k;
int sta[25];
long long t[25];
int w[500005];
struct node{
	int v;
	long long val;
	bool operator <(const node&x)const{
		return x.val<val;
	}
};
struct ask{
	int aska,askb;
	long long ans;
	int pos;
}askab[100005];
bool cmp1(ask x,ask y){
	return x.aska<y.aska;
}
bool cmp2(ask x,ask y){
	return x.pos<y.pos;
}
bool need[500005];
bool vis[500005];
long long dis[500005];
vector<node> G[500005];
priority_queue<node> Q;
void dij(int fa){
	for(int i=1;i<=m;i++)	dis[i]=4e18;
	for(int i=1;i<=m;i++)	vis[i]=false;
	dis[fa]=0,vis[fa]=true;
	Q.push({fa,dis[fa]});
	while(!Q.empty()){
		int u=Q.top().v;
		Q.pop();
		vis[u]=true;
		for(auto vv:G[u]){
			if(vis[vv.v])	continue;
			if(dis[vv.v]>(dis[u]+vv.val)){
				dis[vv.v]=dis[u]+vv.val;
				Q.push({vv.v,dis[vv.v]});
			}
		}
	}
	return; 
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>sta[j]>>t[j];
		}
		for(int l=1;l<k;l++){
			for(int r=l+1;r<=k;r++){
				long long temp=t[l]+t[r];
				G[sta[l]].push_back({sta[r],temp});
				G[sta[r]].push_back({sta[l],temp});
			}
		}
	}
	for(int i=1;i<=q;i++){
		cin>>askab[i].aska>>askab[i].askb;
		need[askab[i].aska]=true;
		askab[i].pos=i;
	}
	sort(askab+1,askab+q+1,cmp1);
	
	int cnt=1;
	for(int i=1;i<=m;i++){
		if(need[i])	dij(i);
		while(i==askab[cnt].aska){
			askab[cnt].ans=dis[askab[cnt].askb]+w[askab[cnt].aska]+w[askab[cnt].askb];
			cnt++;
		}
	}
	sort(askab+1,askab+q+1,cmp2);
	for(int i=1;i<=q;i++){
		cout<<askab[i].ans<<endl;
	}
	return 0; 
} 
