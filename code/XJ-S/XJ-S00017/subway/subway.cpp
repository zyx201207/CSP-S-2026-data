#include<bits/stdc++.h>
using namespace std;
const int M=1005,N=5e6+5;

int c,n,m,d,Q;
int sta[M],wa[N],ti[N],dis[N];
struct edge{
	int v,ti;
};
vector<edge> e[N];
struct node{
	int id,d;
};
node q[N];
int head,tail;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++){
		cin>>sta[i];
	}
	for(int i=1,cnt;i<=n;i++){
		cin>>cnt;
		for(int j=1;j<=cnt;j++){
			cin>>wa[j]>>ti[j];
		}
		for(int j=1;j<=cnt;j++){
			for(int k=j+1;k<=cnt;k++){
				e[wa[j]].push_back((edge){wa[k],ti[j]+ti[k]});
				e[wa[k]].push_back((edge){wa[j],ti[j]+ti[k]});
			}
		}
	}
	while(Q--){
		memset(dis,0x3f,sizeof(dis));
		int st,en;
		cin>>st>>en;
		head=tail=1;
		q[tail++].id=st;
		dis[st]=0;
		while(head<tail){
			node now=q[head++];
			for(int i=0;i<e[now.id].size();i++){
				int v=e[now.id][i].v; 
				if(dis[now.id]+e[now.id][i].ti<=dis[v]){
					dis[v]=dis[now.id]+e[now.id][i].ti;
					q[tail].id=v;
					tail++;
				}
			}
		}
		cout<<sta[st]+sta[en]+dis[en]<<'\n';
	}
	return 0;
} 
