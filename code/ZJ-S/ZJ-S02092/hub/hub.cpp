#include<bits/stdc++.h>
using namespace std;
const int maxn=1000002;
int c,t;int n,k,u,v;
struct point{
	bool vis;int id,line;vector<int>nid;
}a[maxn];
int len(point s){
	if(s.vis)return 0;
	int dist[maxn];bool flag[maxn];
	memset(dist,0xff,sizeof dist);memset(flag,0,sizeof flag);
	queue<point>q;
	q.push(s);dist[s.id]=0;
	while(!q.empty()){
		point f=q.front();q.pop();flag[f.id]=1;
		for(int i=0;i<f.line;i++){
			if(!a[f.nid[i]].vis&&dist[f.nid[i]]>dist[f.id]+1&&!flag[f.nid[i]]){
				dist[f.nid[i]]=dist[f.id]+1;
				q.push(a[f.nid[i]]);
			}
		}
	}int ans=0;
	for(int i=1;i<=n;i++){
		if(ans<dist[i]&&flag[i]){
			ans=dist[i];
		}
	}
	return ans;
}
int main(){
	freopen("hub.in","r",stdin);freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			a[i].id=i;a[i].line=0;
		}
		for(int i=1;i<=n-1;i++){
			cin>>u>>v;
			a[u].line++;a[v].line++;
			a[u].nid.push_back(v);a[v].nid.push_back(u);
		}
		int ans=0xfffff;
		for(int i=1;i<=n;i++){
			a[i].vis=1;
			for(int j=i+1;j<=n;j++){
				a[j].vis=1;
				int t,dt;
				for(int l=2;l<=k;l++){
					t=-1;dt=-1;
					for(int m=1;m<=n;m++){
						if(len(a[m])>dt){
							dt=len(a[m]);t=m;
						}
					}
					a[t].vis=1;
				}
				ans=min(ans,dt);
				for(int l=1;l<=n;l++)a[l].vis=0;
				a[i].vis=1;
			}
			a[i].vis=0;
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
