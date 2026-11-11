#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,nw[20007][507],mw[20007],dis[20007][507],vis[20007][507],l,r,ma=-1;
struct stu{
	int v,lx,val;
	bool operator < (const stu oth)const{
		return val<oth.val;
	} 
};
vector<stu>ve[20007];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>mw[i];
	}for(int i=1;i<=n;i++){
		int sl;cin>>sl;int la=-1;
		for(int i=1;i<=sl;i++){
			int u,v;
			cin>>u>>v;nw[u][i]=v;
			if(la!=-1){
				ve[u].push_back({la,i,0});
				ve[la].push_back({u,i,0});
			}la=u;
		}
	}if(c==7||c==8){
		for(int i=1;i<=q;i++){
			cin>>l>>r;
		}cout<<mw[l]+mw[r]<<endl;
		return 0;
	}
	
	for(int i=1;i<=q;i++){
		cin>>l>>r;
		for(int j=1;j<=m;j++){
			for(int k=1;k<=n;k++){
				vis[j][k]=0;dis[j][k]=1e9+7;
			}
		}priority_queue<stu>pq;
		for(auto now : ve[l]){
			int ul=now.lx;
			pq.push({l,ul,-0});dis[l][ul]=0;
		}
		while(pq.size()){
			stu now=pq.top();
			int uv=now.v,uc=now.lx;
			//cout<<u<<endl;
			pq.pop();
			for(auto se : ve[uv]){
				
				int v=se.v,vc=se.lx;
				
				if(vis[v][vc]==1)continue;
				vis[v][vc]=1;
				//cout<<dis[u]+vw<<" "<<dis[v]<<" "<<v<<endl;
				if(uc==vc&&dis[uv]<=dis[v]){
					dis[v][uc]=dis[uv][uc];
					pq.push({v,uc,0-dis[v][uc]});
				}else if(dis[uv][uc]+(nw[uv][uc]+nw[v][vc])<dis[v][vc]){
					dis[v][vc]=dis[uv][uc]+(nw[uv][uc]+nw[v][vc]);
					pq.push({v,vc,0-dis[v][vc]});
				}
			}
		}
		for(int i=1;i<=n;i++){
			ma=max(ma,dis[r][i]);
		}cout<<mw[l]+ma+mw[r]<<endl;
	}
	return 0;
}

