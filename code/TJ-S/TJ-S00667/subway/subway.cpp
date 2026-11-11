#include<bits/stdc++.h>
using namespace std;
const int L=1e5+10;
int c,n,m,d,qs,w[L],tp[501][L],dist[L][501];
struct N{
	int p,t,x;
	
	bool operator<(const N y)const{
		return x>y.x;
	}
};
vector<N> mp[L];
vector<int> ed[L];
priority_queue<N> q;

void bfs(int s){
	for(int i=1;i<=m;i++){			
    	for(int t=1;t<=n;t++){
	    	dist[i][t]=500000;
		}
	}
	
	for(int i=0;i<ed[s].size();i++){
		int t=ed[s][i];
		dist[s][t]=tp[t][s];
		N nn={t,s,tp[t][s]};
		q.push(nn);
	}
	while(!q.empty()){
		int p=q.top().p;
		int t=q.top().t;
		int x=q.top().x;
		q.pop();
		
		if(dist[t][p]<x){
			continue;
		}
		
		for(int i=0;i<mp[t].size();i++){
			int np=mp[t][i].p;
			int nt=mp[t][i].t;
			int ws=x;
		//	cout<<nt<<" "<<np<<endl;
			if(np!=p){
				ws+=tp[p][nt]+tp[np][nt];
			}
			if(ws<dist[nt][np]){
				dist[nt][np]=ws;
				N nn={nt,np,ws};
				q.push(nn);
			}			
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>qs;
	for(int i=1;i<=m;i++){
		cin>>w[i];		
	}
	for(int i=1;i<=n;i++){
		int k,a,t,s=-1;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a>>t;
			tp[i][a]=t;
			ed[a].push_back(i);
		
			if(s==-1){
				s=a;
			}
			else{
				N nn={i,a,0};
				mp[s].push_back(nn);
				N nn1={i,s,0};
				mp[a].push_back(nn1);
				s=a;
			}
		}
	}
	while(qs--){
		int x,y;
		cin>>x>>y;
		bfs(x);
		int ans=-1;
	for(int i=0;i<ed[y].size();i++){
		int t=ed[y][i];
		//cout<<t<<" "<< dist[y][t]<<" ";
		    ans=max(ans,w[x]+dist[y][t]+tp[t][y]+w[y]);
    	}	
    	cout<<ans<<endl;
	}
		
	return 0;
} 
