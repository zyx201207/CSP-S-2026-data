#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=505;
const long long X=1LL<<60;
int c,n,m,d,_,w[N],k,u,v;
int head[M],nxt[N],to[N],ln[N],cnt;
long long DIS[M][M],dis[M],len[M][M];
struct node{
	int id;
	long long x;
};
vector<node> s[N];
bool book[M];
struct cmp{
	bool operator()(const node &i,const node &j)const{
		return i.x>j.x;
	}
};
priority_queue<node,vector<node>,cmp> Q;
void dijk(int st){
	for(int i=1;i<=n;i++) book[i]=0,dis[i]=X;
	dis[st]=0;Q.push((node){st,0});
	while(Q.empty()==0){
		int p=Q.top().id;Q.pop();
		if(book[p]) continue; book[p]=1;
		for(int i=head[p];i;i=nxt[i]){
			int q=to[i];
			if(book[q]==0 && dis[q]>dis[p]+ln[i]){
				dis[q]=dis[p]+ln[i];
				Q.push((node){q,dis[q]});
			}
		}
	}
	for(int i=1;i<=n;i++) DIS[st][i]=dis[i];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>c>>n>>m>>d>>_;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		while(k--){
			cin>>u>>v;
			s[u].push_back((node){i,v});
		}
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)len[i][j]=X;
	for(int i=1;i<=m;i++){
		for(int l=1;l<s[i].size();l++){
			node p=s[i][l];
			for(int r=0;r<l;r++)
			len[s[i][r].id][p.id]=len[p.id][s[i][r].id]=
			min(len[p.id][s[i][r].id],p.x+s[i][r].x);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(len[i][j]<X)
			cnt++,nxt[cnt]=head[i],to[cnt]=j,ln[cnt]=len[i][j],head[i]=cnt;
		}
	}
	for(int i=1;i<=n;i++) dijk(i);
	for(int i=1;i<=n;i++) DIS[i][i]=0;
	while(_--){
		cin>>u>>v;
		long long mn=X;
		for(int i=0;i<s[u].size();i++){
			node p=s[u][i];
			for(int j=0;j<s[v].size();j++)
			mn=min(mn,DIS[p.id][s[v][j].id]+p.x+s[v][j].x);
		}
		cout<<mn+w[u]+w[v]<<"\n";
	}
	return 0;
}
