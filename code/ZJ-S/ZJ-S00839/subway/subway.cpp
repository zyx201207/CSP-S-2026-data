#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k;
vector<int>v[5005];
int w[50005],t[505][50005],l[50005][505];
int ans=INT_MAX;
void dfs(int now,int cnt,int mdd,int pre,int line){
	//cout<<now<<" "<<cnt<<" "<<line<<"\n";
	if(now==mdd){
		ans=min(ans,cnt);
		return ;
	}
	for(int u:v[now]){
		if(u!=pre){
			for(int j=1;j<=n;j++){
				if(l[u][j])dfs(u,cnt+t[line][now]+t[line][u],mdd,now,j);
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int pre;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a;
			cin>>a;
			cin>>t[i][a];
			l[a][i]=1;
			if(j>1){
				v[pre].push_back(a);
				v[a].push_back(pre);
			}
			pre=a;
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		ans=INT_MAX;
		for(int i=1;i<=n;i++){
			if(l[x][i])dfs(x,0,y,-1,i);
		}
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}