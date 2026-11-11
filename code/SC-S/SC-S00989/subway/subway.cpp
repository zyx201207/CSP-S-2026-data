#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[1003],t[1003][503],tag[1003];
long long ans;
struct Node{
	int id;
	long long tim;
};
vector<Node> g[1003];
queue<int> st;
long long val[1003];
void dfs(int now,int lst,long long tim){
	if(tim>=ans) return;
	if(now==lst){
		ans=min(ans,tim);
		return;
	}
	for(int i=1;i<=n;i++){
		if(t[now][i]!=0)
			for(int j=1;j<=m;j++)
				if(t[j][i]!=0&&tag[j]!=1) tag[j]=1,dfs(j,lst,tim+t[now][i]+t[j][i]),tag[j]=0;
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%d",&w[i]);
	if(c>=7&&c<=11){
		for(int i=1;i<=n;i++){
			int k,id1,id2,tim1,tim2;
			scanf("%d",&k);
			if(k>=1) scanf("%d%d",&id1,&tim1);
			if(k==2){
				scanf("%d%d",&id2,&tim2);
				g[id1].push_back({id2,tim1+tim2}),g[id2].push_back({id1,tim1+tim2});
			}
		}
		for(int i=1;i<=q;i++){
			for(int j=1;j<=m;j++) val[j]=1e16;
			int u,v;
			scanf("%d%d",&u,&v);
			val[u]=0,st.push(u);
			while(!st.empty()){
				int tp=st.front();
				st.pop();
				for(Node nxt:g[tp])
					if(val[nxt.id]>val[tp]+nxt.tim) st.push(nxt.id),val[nxt.id]=val[tp]+nxt.tim;
			}
			printf("%lld\n",w[u]+w[v]+val[v]);
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			int id;
			scanf("%d",&id);
			scanf("%d",&t[id][i]);
		}
	}
	for(int i=1;i<=q;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		ans=1e16,tag[u]=1,dfs(u,v,0),tag[u]=0;
		printf("%lld\n",w[u]+w[v]+ans);
	}
	return 0;
}