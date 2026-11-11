#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
priority_queue<P,vector<P>,greater<P> >q;
vector<int> a[510],l[510];
vector<int> e[500010],t[500010];
bool flag[510];
int ans[510][510],K,A,c,n,m,d,qq,w[500010];
void dijkstra(int s){
	memset(flag,0,sizeof(flag));
	q.push({s,0});
	flag[s]=1;
	ans[s][s]=0;
	while(!q.empty()){
		P t=q.top();
		q.pop();
		int u=t.first,le=t.second;
		for(int i=0;i<a[u].size();i++){
			if(flag[a[u][i]]) continue;
			if(ans[s][i]>ans[s][u]+l[u][i]){
				ans[s][i]=ans[s][u]+l[u][i];
				q.push({a[u][i],ans[u][i]});
				flag[a[u][i]]=1;
			}
		}
	}
	return;
}
int majn(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>qq;
	for(int i=1;i<=m;i++)
	cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>K;
		for(int i=1,T;i<=K;i++){
			cin>>A>>T;
			t[A].push_back(T);
			e[A].push_back(i);
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<e[i].size()-1;j++){
			for(int lll=j+1;lll<=e[i].size();lll++){
				a[e[i][j]].push_back(e[i][lll]);
				l[e[i][j]].push_back(t[i][j]+t[i][lll]);
				a[e[i][lll]].push_back(e[i][lll]);
				l[e[i][lll]].push_back(t[i][j]+t[i][lll]);
			}
		}
	}
	for(int i=1;i<=505;i++)
	for(int j=1;j<=505;j++)
	ans[i][j]=INT_MAX;
	for(int i=1;i<=n;i++)
	dijkstra(i);
	for(int i=1,x,y,ANS=100000001;i<=qq;i++){
		cin>>x>>y;
		for(int o=0;o<e[y].size();o++)
		for(int j=0;j<e[x].size();j++){
			ANS=min(ans[e[x][j]][e[y][o]],ANS);
		}
		cout<<ANS<<'\n';
	}
	return 0;
}
//我写了1h+的程序错了，现在18:23了
//根本找不到错因
//毁灭吧
