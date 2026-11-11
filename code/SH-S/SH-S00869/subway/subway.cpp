#include<bits/stdc++.h>
using namespace std;
const int maxn=510;
const int maxm=500010;
long long tme[maxm];
int snum[maxm];
bool vis[maxn];
vector<int> sta[maxn];
int ch[maxm][maxn];
long long c,n,m,d,q,init=0;
long long ans=LLONG_MAX;
void dfs(int start,int end,long long curtime){
	int flag=0;
	for(int i=1;i<=snum[start];i++){
		if(vis[i]){
			continue;
		}
		for(int j=1;j<=sta[i].size();j++){
			if(sta[i][j]==end){
				curtime+=ch[start][i]+ch[end][i];
				ans=min(curtime,ans);
				memset(vis,false,sizeof(vis));
				flag=1;
				return;
			}else if(snum[j]>1){
				vis[i]=true;
				dfs(j,end,curtime+ch[start][i]+ch[j][i]);
			}
		}
		vis[i]=false;
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>tme[i];
	}
	for(int i=1;i<=n;i++){
		int num;
		cin>>num;
		for(int j=1;j<=num;j++){
			int a,t;
			cin>>a>>t;
			snum[a]++;
			sta[i].push_back(a);
			ch[a][i]=t;
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		memset(vis,false,sizeof(vis));
		ans=LLONG_MAX;
		cin>>x>>y;
		init=tme[x]+tme[y];
		dfs(x,y,init);
		cout<<ans<<"\n";
	}
	return 0;
}
