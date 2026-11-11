#include<algorithm>
#include<cstdio>
#include<iostream>
#include<queue> 
#include<utility>
#include<vector>
using namespace std;
int c,T;
int n,k;
vector<int> nxt[1200000];
int dep[1200000];
pair<int,int> seq[1200000];
int others[1200000];
int ma_dep[1200000];
int seqc;
void dfs0(int cur,int pa){
	dep[cur]=dep[pa]+1;
	for(int v:nxt[cur]){
		if(v!=pa){
			dfs0(v,cur);
		}
	}
}
bool dfs1(int cur,int pa,int target){
	int mad = dep[cur];
	bool found = cur==target;
	for(int v:nxt[cur]){
		if(v!=pa){
			if(dfs1(v,cur,target)){
				found = true;
			}else{
				mad = max(mad,dep[v]);
			}
		}
	}
	if(found){
		seq[++seqc]={mad-dep[cur],cur};
	}
	return found;
}
int sml,smr;
void dfs2(int cur,int pa){
	ma_dep[cur]=dep[cur]=dep[pa]+1;
	for(int v:nxt[cur]){
		if(v!=pa&&(v!=smr||cur!=sml)&&(v!=sml||cur!=smr)){
			dfs2(v,cur);
			ma_dep[cur]=max(ma_dep[cur],ma_dep[v]);
		}
	}
}
void solve(){
	cin>>n>>k;
	for(int i = 1;i <= n;i++){
		nxt[i].clear();
	}
	for(int i = 1;i < n;i++){
		int u,v;
		cin>>u>>v;
		nxt[u].push_back(v);
		nxt[v].push_back(u);
	}
	dfs0(1,0);
	int x = 0;
	for(int i = 1;i <= n;i++){
		if(dep[i]>dep[x]) x=i;
	}
	dfs0(x,0);
	int y = 0;
	for(int i = 1;i <= n;i++){
		if(dep[i]>dep[y]) y=i;
	}
	seqc=0;
	dfs1(y,0,x);
//	for(int i = 1;i <= seqc;i++){
//		cout<<"#"<<seq[i]<<'\n';
//	}
	int ml,mr,mml,mmr;
	int al,ar;
	ml=(1+seqc)>>1;
	mr=((1+seqc)>>1)+1;
	mml=(1+ml)>>1;
	mmr=(mr+seqc)>>1;
	priority_queue<pair<int,int>> pqf;
	priority_queue<pair<int,int>> pqb;
	int mi;
	mi = 1e9;
	for(int i = 1;i <= ml;i++){
		pqf.push({seq[i].first-i,i});
	}
	for(int i = ml;i >= 1;i--){
		pqb.push({seq[i].first+i,i});
		while(pqf.size()&&pqf.top().second>=i) pqf.pop();
		if(max(pqf.top().first+i,pqb.top().first-i)<mi){
			mi=max(pqf.top().first+i,pqb.top().first-i);
			mml=i;
		}
	}
	while(pqf.size()) pqf.pop();
	while(pqb.size()) pqb.pop();
	for(int i = mr;i <= seqc;i++){
		pqf.push({seq[i].first-i,i});
	}
	for(int i = seqc;i >= mr;i--){
		pqb.push({seq[i].first+i,i});
		while(pqf.size()&&pqf.top().second>=i) pqf.pop();
		if(max(pqf.top().first+i,pqb.top().first-i)<mi){
			mi=max(pqf.top().first+i,pqb.top().first-i);
			mmr=i;
		}
	}
	while(pqf.size()) pqf.pop();
	while(pqb.size()) pqb.pop();
	ml=(mml+mmr)>>1;
	mr=((mml+mmr)>>1)+1;
	sml = seq[ml].second;
	smr = seq[mr].second;
	al = seq[mml].second;
	ar = seq[mmr].second;
//	cout<<sml<<" "<<smr<<" "<<al<<" "<<ar<<'\n';
	dfs2(al,0);
	dfs2(ar,0);
	priority_queue<pair<int,int>> pq;
	int cnt = 0;
	pq.push({ma_dep[al]-dep[al],al});
	pq.push({ma_dep[ar]-dep[ar],ar});
	while(cnt<k){
		++cnt;
		auto cur = pq.top();
//		cout<<cur.second<<'\n';
		pq.pop(); 
		for(int v:nxt[cur.second]){
			if(dep[v]>dep[cur.second]&&(v!=smr||cur.second!=sml)&&(v!=sml||cur.second!=smr)){
				pq.push({ma_dep[v]-dep[v],v});
			}
		}
	}
	if(cnt==k) cout<<pq.top().first+1<<'\n';
	else cout<<0<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("hub.in","r",stdin); 
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--) solve();
	return 0;
} 
