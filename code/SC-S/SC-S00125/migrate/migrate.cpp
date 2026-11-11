#include<bits/stdc++.h>
using namespace std;
const int N=5010;
int x[N];
vector<int> G[N];
int d[N],cnt[N];
bool edgevis[N][N];
int n,D;
void BFS(int start){
	queue<pair<int,int> > q; // [w,id]
	q.push({0,start});
	d[start]=0;
	while(!q.empty()){
		pair<int,int> top=q.front(); q.pop();
		int u=top.second,w=top.first;
//		cout<<"in "<<u<<' '<<w<<'\n';
		for(int v:G[u]){
//			cout<<"inin v"<<v<<endl;
			if(edgevis[u][v]==1||edgevis[v][u]==1) continue;
			edgevis[u][v]=1;
			int dd=d[u]+1;
//			cout<<"inin dd"<<dd<<endl;
			if(dd==d[v]){
				cnt[v]++;
			}
			else if(dd<d[v]){
				d[v]=dd,cnt[v]=1,q.push({dd,v});
			}
		}
//		cout<<"d\n";
//			for(int i=1;i<=n;i++) cout<<d[i]<<' ';
//			cout<<endl;
//			cout<<"cnt\n";
//			for(int i=1;i<=n;i++) cout<<cnt[i]<<' ';
//			cout<<endl;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t; cin>>c>>t;
	for(int Case=1;Case<=t;Case++){
		cin>>n>>D;
		for(int i=1;i<=n;i++) cin>>x[i],G[i].clear();
		if(n>5010){
			int delta=x[2]-x[1];
			if(D<delta){
				cout<<0<<endl; continue;
			}
			cout<<n-D/delta-1<<endl;
			continue;
		}
		for(int l=1;l<n;l++){
			for(int r=l+1;r<=n;r++){
				if(x[r]-x[l]<=D){
					G[l].push_back(r);
					G[r].push_back(l);
				}
			}
		}
		
//		for(int i=1;i<=n;i++){
////			cout<<"i="<<i<<endl;
//			for(int j:G[i]){
//				cout<<j<<' ';
//			}
//			cout<<endl;
//		}
//		cout<<"----\n";
		
		int ans=0;
		for(int start=1;start<=n;start++){
//			cout<<"----====start="<<start<<endl;
			memset(d,0x3f3f3f3f,sizeof(d));
			memset(cnt,0,sizeof(cnt));
			memset(edgevis,false,sizeof(edgevis));
			BFS(start);
//			cout<<"d\n";
//			for(int i=1;i<=n;i++) cout<<d[i]<<' ';
//			cout<<endl;
//			cout<<"cnt\n";
//			for(int i=1;i<=n;i++) cout<<cnt[i]<<' ';
//			cout<<endl;
			for(int i=1;i<=n;i++){
				ans+=(cnt[i]==2);
			}
		}
		cout<<ans/2<<'\n';
	}
	return 0;
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/