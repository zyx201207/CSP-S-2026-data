#include<bits/stdc++.h>
using namespace std;

const int N=1e6+5;
int c,T,n,k,jd[15],dist[N],ans;
bool t[N];
vector<int> edge[N];

inline void dfs(int x,int gs){
	if(gs==k+1){
		memset(t,false,sizeof(t));
		set<int> st;
		for(int i=1;i<=k;i++)
			st.insert(jd[i]);
		int cs=0;
		for(int i=1;i<=k;i++){
			if(!t[i])
				cs++;
			for(auto j:edge[jd[i]])
				if(st.find(j)!=st.end()&&!t[j])
					t[j]=true;
			t[i]=true;
		}
		if(cs>2)
			return;
		queue<int> que;
		memset(dist,127,sizeof(dist));
		memset(t,false,sizeof(t));
		for(int i=1;i<=k;i++){
			que.push(jd[i]);
			t[jd[i]]=true;
			dist[jd[i]]=0;
		}
		while(!que.empty()){
			int x=que.front();
			que.pop();
			for(auto y:edge[x]){
				if(t[y])
					continue;
				dist[y]=dist[x]+1;
				t[y]=true;
				que.push(y);
			}
		}
		int ma=0;
		for(int i=1;i<=n;i++)
			ma=max(ma,dist[i]);
		ans=min(ans,ma);
		return;
	}
	for(int i=x;i<=n;i++){
		jd[gs]=i;
		dfs(i+1,gs+1);
		jd[gs]=0;
		dfs(i+1,gs);
	}
	return;
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&T);
	for(;T--;){
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++)
			edge[i].clear();
		for(int i=1;i<n;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			edge[u].push_back(v);
			edge[v].push_back(u);
		}
		ans=N;
		dfs(1,1);
		printf("%d\n",ans);
	}
	return 0;
}