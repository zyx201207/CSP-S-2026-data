#include<bits/stdc++.h>
using namespace std;
struct ggg{
	int num,dep;
};
int c,T,n,k,ans,hubs[1000005],vis[1000005];
vector<int>a[1000005];
queue<ggg>q;
void dfs(int lst,int dep,int cnt){
//	for(int i=1;i<=n;i++)cout<<hubs[i]<<" ";
//	cout<<"  "<<dep<<" "<<cnt<<"\n";
	if(dep==k){
		int maxn=-1;
		for(int i=1;i<=n;i++){
			if(hubs[i])continue;
			memset(vis,0,sizeof(vis));
			while(q.size())q.pop();q.push({i,0});vis[i]=1;
			while(q.size()){
				int xx=q.front().num,yy=q.front().dep;q.pop();
				if(hubs[xx]){
					maxn=max(maxn,yy);break;
				}
				for(int i=0;i<a[xx].size();i++){
					if(!vis[a[xx][i]]){
						vis[a[xx][i]]=1;q.push({a[xx][i],yy+1});
					}
				}
			}
		}
		ans=min(ans,maxn);return ;
	}for(int i=lst+1;i<=n;i++){
		int f=0;
		for(int j=0;j<a[i].size();j++){
			if(hubs[a[i][j]]){
				f=1;break;
			}
		}
		if(!f&&cnt==2)continue;
		hubs[i]=1;
		dfs(i,dep+1,cnt+1-f);
		hubs[i]=0;
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&T);
	while(T--){
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++)a[i].clear();
		for(int i=1,u,v;i<n;i++){
			scanf("%d%d",&u,&v);
			a[u].push_back(v);a[v].push_back(u);
		}ans=1e9;
		dfs(0,0,0);
		cout<<ans<<"\n";
	}//18:18
	return 0;
}
//shu de zhong xin? bu zhi dao shen me suan fa
//guess:purple
//hai shi bu hui,bao li ye bu hui da le,nao zi dang ji le
