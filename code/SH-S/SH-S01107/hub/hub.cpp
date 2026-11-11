#include<bits/stdc++.h>
using namespace std;
const int N=19;
vector<int> to[N],vans;
bool hv[N];
int id[N],d[N];
int root(int u){
	while(id[u]!=u)u=id[u]=id[id[u]];
	return u;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	if(c>=4)return 0;
	while(t--){
		int n,k;
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			to[u].push_back(v);
			to[v].push_back(u);
		}
		int ans=n;
		for(int i=3;i<(1<<n);i++){
			int ppc=__builtin_popcount(i);
			if(ppc!=k)continue;
			for(int j=0;j<n;j++)
			    hv[j+1]=((i>>j)&1);
			for(int j=1;j<=n;j++)if(hv[j])id[j]=j;
			for(int j=1;j<=n;j++){
				for(int e=0;e<to[j].size();e++){
					int k=to[j][e];
					if(hv[j]&&hv[k])id[root(j)]=root(k);
				}
			}
			int cnt=0;
			for(int j=1;j<=n;j++){
				if(hv[j]&&id[j]==j)cnt++;
			}
			if(cnt>2)continue;
			for(int j=1;j<=n;j++)d[j]=-1;
			queue<int> q;
			for(int j=1;j<=n;j++)
				if(hv[j]){
					d[j]=0;
					q.push(j);
				}
			while(!q.empty()){
				int u=q.front();
				q.pop();
				for(int j=0;j<to[u].size();j++){
					int v=to[u][j];
					if(d[v]==-1){
						d[v]=d[u]+1;
						q.push(v);
					}
				}
			}
			int mx=*max_element(d+1,d+1+n);
//			cout<<i<<" "<<mx<<"\n";
			ans=min(ans,mx);
		}
		vans.push_back(ans);
		for(int i=1;i<=n;i++)to[i].clear();
	}
//	freopen("hub2.ans","r",stdin);
//	int cnt=0;
	for(int i=0;i<vans.size();i++){
		cout<<vans[i]<<"\n";
//		int ac;
//		cin>>ac;
//		cout<<i<<" "<<vans[i]<<" "<<ac<<"\n";
//		cnt+=(vans[i]==ac);
	}
//	cout<<vans.size()<<" "<<cnt<<"\n";
	return 0;
}
// 为什么没有n<=20部分分？ 
