#include <bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[111111],k[111111],x,y,lll;
vector<pair<int,long long> > a[111111];
vector<int> jg[111111];
long long bfs1(long long xx,long long yy){
	queue<int> qq;
	qq.push(xx);
	long long vis[111111]={};
	while(qq.size()){
		int pp=qq.front();
		qq.pop();
		for(int i=0;i<jg[pp].size();i++){
			int l=jg[pp][i];
			for(int j=0;j<a[l].size();j++){
				
				int ppp=a[l][j].first;
				
				if(vis[ppp]==0&&ppp!=xx){
					qq.push(ppp);
					vis[ppp]=vis[pp]+1;
				} 
				if(ppp==yy) return vis[ppp]*a[l][j].second*2+w[xx]+w[yy];
			}
		}
	}
	
}//O(n*d*q)¸´ÔÓ¶È£¬12~15¿¨Ïß¹ý 
long long bfs2(long long xx,long long yy){
	queue<int> qq;
	qq.push(xx);
	lll=0;
	long long vis[111111]={};
	for(int i=0;i<=111110;i++) vis[i]=111111111111111111;
	vis[xx]=0;
	while(qq.size()){
		int pp=qq.front();
		qq.pop();
		for(int i=0;i<jg[pp].size();i++){
			int l=jg[pp][i];
			for(int j=0;j<a[l].size();j++){
				
				int ppp=a[l][j].first;
				if(ppp==pp) lll=a[l][j].second;
				if(vis[ppp]>vis[pp]+1&&ppp!=xx){
					qq.push(ppp);
					vis[ppp]=vis[pp]+lll+a[l][j].second;
				} 
			}
		}
	}
	return vis[yy]+w[xx]+w[yy];
}

int main(int argc, char** argv) {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>x>>y;
			a[i].push_back(make_pair(x,y));
			jg[x].push_back(i);
		}
	}
	while(q--){
		cin>>x>>y;
		if(c<=6) cout<<bfs2(x,y)<<endl;
		else cout<<bfs1(x,y)<<endl;
	}
	return 0;
}
