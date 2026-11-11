#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
using namespace std;
typedef pair<int,int> P;
const int N=505,M=5e5+5;
int c,n,m,d,q,w[M],k[N],cnt,dis[M<<2];
vector<P>E[M<<2];
void dfs(int st){
	memset(dis,0x3f,sizeof dis);dis[st]=0;
	priority_queue<P,vector<P>,greater<P> >q;
	q.push(mp(-1,st));
	while(!q.empty()){
		P x=q.top();q.pop();
		int u=x.second,ww=x.first;
		if(ww<=dis[u]){
			for(auto as:E[u]){
				int v=as.first,w=as.second;
				if(dis[u]+w<dis[v]){
					dis[v]=dis[u]+w;
					q.push(mp(dis[v],v));
				}
			}
		}
		
	}
	return ;
}
int main(){
	//freopen("subway4.in","r",stdin);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	cnt=m;
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
		cnt++;
		E[i].push_back(mp(cnt,w[i]));
		E[cnt].push_back(mp(i,w[i]));
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		for(int j=1,a,t;j<=k[i];j++){
			scanf("%d%d",&a,&t);
			++cnt;
			E[cnt].push_back(mp(m+a,t));
			E[m+a].push_back(mp(cnt,t));
			if(j>=2){
				E[cnt].push_back(mp(cnt-1,0));
				E[cnt-1].push_back(mp(cnt,0));
			}
		}
	}
	for(int i=1,x,y;i<=q;i++){
		scanf("%d%d",&x,&y);
		dfs(x);
		printf("%d\n",dis[y]);
	}
	return 0;
}
/*
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
*/
