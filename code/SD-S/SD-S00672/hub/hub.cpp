#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,h[15];
vector<int> to[15];
bool f[15],flag[15];
void dfs(int now,int fa){
	flag[now]=0;
	for (int next:to[now]){
		if (next==fa||flag[next]==0)
			continue;
		dfs(next,now);
	}
}
bool check(){
	int tot=0;
	for (int i=1;i<=n;i++)
		flag[i]=f[i],h[i]=0;
	for (int i=1;i<=n;i++)
		if (flag[i]){
			tot++;
			dfs(i,0);
		}
	if (tot>2)
		return 0;
	return 1;
}
void fz(int now,int fa){
	for (int next:to[now]){
		if (next==fa)
			continue;
		if (h[next]==0)
			h[next]=h[now]+1;
		else
			h[next]=min(h[next],h[now]+1);
		fz(next,now);
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while (t--){
		int ans=-1;
		cin>>n>>k;
		for (int i=1;i<=n;i++)
			to[i].clear();
		for (int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			to[u].emplace_back(v);
			to[v].emplace_back(u);		
		}
		for (int i=1;i<=1<<n;i++){
			int tot=0,maxx=0;
			for (int j=0;j<n;j++){
				if (i&(1<<j))
					f[j+1]=1,tot++;
				else
					f[j+1]=0;
			}
			if (tot!=k)
				continue;
			if (check()==0)
				continue;
			for (int j=1;j<=n;j++)
				if (f[j]){
					h[j]=1;
					fz(j,0);
				}
			for (int j=1;j<=n;j++){
//				cout<<h[j]<<' ';
				if (f[j]==0)
					maxx=max(maxx,h[j]-1);
			}
//			cout<<endl;
			if (ans==-1)
				ans=maxx;
			else
				ans=min(ans,maxx);
		}
		cout<<ans<<endl;
	}
	return 0;
}
