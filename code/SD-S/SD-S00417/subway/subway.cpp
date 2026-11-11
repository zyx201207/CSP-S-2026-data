#include <bits/stdc++.h>
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define ll long long
using namespace std;
const int N=5e6+5;
int w[N],e[N],ne[N],h[N],dist[N],v[N];
ll c,n,m,d,Q;
int idx=0;
queue <int> q;
void add(int a,int b,int c){
	e[idx]=b;
	w[idx]=c;
	ne[idx]=h[a];
	h[a]=idx;
	idx++;
}
void spfa(int s){
	memset(dist,0x3f,sizeof(dist));
	v[s]=1;
	dist[s]=0;
	q.push(s);
	while(!q.empty()){
		int id=q.front();
		q.pop();
		v[id]=0;
		for(int k=h[id];k!=-1;k=ne[k]){
			if(dist[e[k]]>dist[id]+w[k]){
				dist[e[k]]=dist[id]+w[k];
				if(!v[e[k]]){
					q.push(e[k]);
					v[e[k]]=1;
				}
			}
		}
	}
}
int start_[N],end_[N];
int ans[N];
vector <int> tongji[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	memset(h,-1,sizeof(h));
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++){
		int x;
		cin>>x;
		int u=m+i;
		add(u,i,x);
		add(i,u,x);
//		cout<<u<<" "<<i<<" "<<x<<"\n";
	}
	for(int _=1;_<=n;_++){
		int k;
		cin>>k;
		int u=2*m+_; 
		for(int i=1;i<=k;i++){
			int x,t;
			cin>>x>>t;
			int v=m+x;
			add(u,v,t);
			add(v,u,t);
//			cout<<v<<" "<<u<<" "<<t<<"\n";
		}
	}
	for(int i=1;i<=Q;i++){
		cin>>start_[i]>>end_[i];
		tongji[start_[i]].push_back(i);
	}
	for(int i=1;i<=m;i++){
		if(tongji[i].size()!=0){
			spfa(i);
			for(auto it:tongji[i]){
				ans[it]=dist[end_[it]];
			} 
		}
	}
	for(int i=1;i<=Q;i++){
		cout<<ans[i]<<"\n";
	}
//	for(int i=1;i<=m;i++){
//		if(tongji[i].size()!=0){
//			cout<<i<<":";
//			for(auto it:tongji[i]){
//				ans[it]=dist[end_[it]];
//				cout<<i<<","<<end_[it]<<" ";
//			} 
//		}
//	}
//	spfa(1);
//	cout<<dist[3]<<"\n"<<dist[2];
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2


0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/
