#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=505,M=5e5+505,D=25,Q=1e5+5;
struct edge{
	int to,val;
};
struct node{
	int to,val;
	bool operator<(const node& X)const{
		return X.val<val;
	}
};
int c,n,m,d,T;
int w[M];
vector<edge> v[M];
priority_queue<node> q;
bool book[M];
//int dis[505][51005];
vector<int> dis[505];
//250000000
void wk(int he){
	for(int fg=1;fg<=m+n+1;fg++){
		book[fg]=0;
	//	dis[he-m][fg]=9223372036854775807;
		dis[he-m].push_back(9223372036854775807);
	}
	q.push((node){he,0});
	dis[he-m][he]=0;
	while(!q.empty()){
		node tmp=q.top();
		q.pop();
		int now=tmp.to,d=tmp.val;
		if(book[now])continue;
		book[now]=1;
		for(int fg=0;fg<v[now].size();fg++){
			edge TP=v[now][fg];
			int u=TP.to,d2=TP.val;
			if(d2+d<dis[he-m][u]){
				dis[he-m][u]=d2+d;
				q.push((node){u,dis[he-m][u]});
			    //if(dis[he][u]<=0)cout<<"";
			}
		}
	}
}
signed main(){
//	system("fc subway7.out subway7.ans");
//	system("fc subway5.out subway5.ans");
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>T;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	int a1,t1,k;
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a1>>t1;
			v[a1].push_back((edge){m+i,t1});
			v[m+i].push_back((edge){a1,t1});
			//p[a1].push_back(edge{m+i,t1});
		}
	}
	for(int i=1;i<=n;i++){wk(m+i);}
	int x,y,ans,mi;
	while(T--){
		cin>>x>>y;
		ans=w[x]+w[y];mi=9223372036854775807;
		for(int fg=0;fg<v[x].size();fg++){
			edge TP1=v[x][fg];
			int st1=TP1.to;
			for(int fg2=0;fg2<v[y].size();fg2++){
				edge TP2=v[y][fg2];int st2=TP2.to;
				mi=min(mi,dis[st1-m][x]+dis[st2-m][y]+dis[st1-m][st2]);
			}
		}
		cout<<mi+ans<<"\n";
	}
}
//1 5
//2 7
//4 6
//
//2 3
//3 4
//5 7
//4+5+7+3+4+9
