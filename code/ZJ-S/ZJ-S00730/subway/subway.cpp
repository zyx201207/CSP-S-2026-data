#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k[505],a[500005],x,y;
long long w[500005],t[500005];
// case #7-11
const long long INF=0x3f3f3f3f3f3f3f3f;
vector< pair<long long,int> > Node[510];// {val,to}
long long Dist[510][510];
priority_queue< pair<long long,int> > pQueue;// {-val,to}
// case #12-19
long long T,ans=0;
vector<int> A[505];// road to station
vector<int> B[500005];//st to rd
bool ok[500005];
queue< pair<int,long long> > Queue;// {station,val}
int main(){
//	freopen("subway4.in","r",stdin);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int v=1;v<=m;v++) scanf("%lld",&w[v]);
	if(c>=7&&c<=11){
		for(int i=1;i<=n;i++){
			scanf("%d",&k[i]);
			for(int j=1;j<=k[i];j++){
				scanf("%d%lld",&a[j],&t[j]);
			}
			if(k[i]==2){
				Node[a[1]].push_back({t[1]+t[2],a[2]});
				Node[a[2]].push_back({t[1]+t[2],a[1]});
			}
		}
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				Dist[i][j]=(i==j)?0:INF;
			}
		}
		while(q--){
			scanf("%d%d",&x,&y);
			if(x>y) swap(x,y);
			if(Dist[x][y]!=INF){
				printf("%lld\n",Dist[x][y]+w[x]+w[y]);
				continue;
			}
			for(int i=0;i<(int)Node[x].size();i++){
				pQueue.push({-Node[x][i].first,Node[x][i].second});
			}
			int now=x;
			while(!pQueue.empty()){
				now=pQueue.top().second;
				Dist[x][now]=-pQueue.top().first;
				while(!pQueue.empty()&&Dist[x][pQueue.top().second]!=INF){
					pQueue.pop();
				}
				for(int i=0;i<(int)Node[now].size();i++){
					if(Dist[x][Node[now][i].second]==INF){
						pQueue.push({-Dist[x][now]-Node[now][i].first,Node[now][i].second});
					}
				}
			}
			printf("%lld\n",Dist[x][y]+w[x]+w[y]);
		}
	}
	else if(c>=12&&c<=19){
		for(int i=1;i<=n;i++){
			scanf("%d",&k[i]);
			for(int j=0;j<k[i];j++){
				scanf("%d%lld",&a[j],&t[j]);
				A[i].push_back(a[j]);
				B[a[j]].push_back(i);
				T=t[j];
			}
		}
		while(q--){
			for(int i=1;i<=m;i++) ok[i]=false;
			scanf("%d%d",&x,&y);
			Queue.push({x,0});
			ok[x]=true;
			bool flag=false;
			while(!Queue.empty()){
				int nowst=Queue.front().first;
				long long nowdist=Queue.front().second;
				Queue.pop();
				for(int i=0;i<(int)B[nowst].size();i++){
					for(int j=0;j<(int)A[B[nowst][i]].size();j++){
						if(A[B[nowst][i]][j]==y){
							flag=true;
							ans=nowdist+T*2;
							break;
						}
						if(ok[A[B[nowst][i]][j]]) continue;
						ok[A[B[nowst][i]][j]]=true;
						Queue.push({A[B[nowst][i]][j],nowdist+T*2});
					}
					if(flag) break;
				}
				if(flag){
					while(!Queue.empty()) Queue.pop();
				}
			}
			printf("%lld\n",ans+w[x]+w[y]);
		}
	}
	return 0;
}
//I have made all my efforts
