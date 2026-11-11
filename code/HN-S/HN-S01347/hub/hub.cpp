#include<bits/stdc++.h>
#define P pair<int,int>
using namespace std;
const int maxn=1e6+6;
vector <int> near[maxn];
int c,t,n,k,lev[maxn],u,v,d[maxn],ans;
bool used[maxn];
void pre(){
	bool b[maxn];
	memset(b,0,sizeof(b));
	queue < P > que;
	que.push(P(0,1));
	while(!que.empty()){
		P p=que.front();que.pop();
		int j=p.second;
		for(unsigned int i=0;i<near[j].size();i++){
			if(b[near[j][i]]) continue;
			b[near[j][i]]=1;
			lev[near[j][i]]=lev[j]+1;
			que.push(P(p.first+1,near[j][i]));
		}
	}
}
void f(int lv,bool e){
	if(lv>k){
		memset(d,-1,sizeof(d));
		for(int i=1;i<=n;i++){
			if(used[i]){
				d[i]=0;
				bool b[maxn];
				memset(b,0,sizeof(b));
				queue <int> que;
				que.push(i);
				while(!que.empty()){
					int p=que.front();que.pop();
					for(unsigned int k=0;k<near[p].size();k++){
						if(b[near[p][k]]) continue;
						b[near[p][k]]=1;
						if(d[near[p][k]]<0||d[near[p][k]]>d[p]+1){
							d[near[p][k]]=d[p]+1;
						}
						que.push(near[p][k]);
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			ans=max(ans,d[i]);
		}
		return ;
	}
	bool po[maxn];
	memset(po,0,sizeof(po));
	for(int i=1;i<=n;i++){
		if(lev[i]==lv-1){
			for(unsigned int j=0;j<near[i].size();j++){
				if(!used[near[i][j]]){
					po[near[i][j]]=1;
					used[near[i][j]]=1;
					f(lv+1,e);
					used[near[i][j]]=0;
				}
			}
		}
	}
	if(!e){
		for(int i=1;i<=n;i++){
			if(!used[i]&&!po[i]){
				used[i]=1;
				f(lv+1,e);
				used[i]=0;
			}
		}
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout); 
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%d",&n,&k);
		for(int i=1;i<n;i++){
			scanf("%d%d",&u,&v);
			near[u].push_back(v);
			near[v].push_back(u);
		}
		pre();
		f(1,0);
		printf("%d\n",ans);
	}
	return 0;
}
