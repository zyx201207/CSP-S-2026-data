#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005];
//n:线路数量,m:站数,d:单站点最大线数,q:计划数
map<int,int>t[500001];//记录换站时间
bool vis[500005];//标记是否经过
pair<int,int>line[501];
vector<pair<int,int>>sets[500005];
void bfs(int start,int end,int already,int &ans){
	if(already>=ans)return;
	if(start==end){
		ans=min(ans,already);
		return;
	}
	for(auto s:sets[start]){
		if(!vis[s.first]){
			vis[s.first]=true;
			bfs(s.first,end,already+t[start][s.second]+t[s.first][s.second],ans);
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,ti;
			cin>>a>>ti;
			t[a][i]=ti;
			pair<int,int> set=line[i];
			if(line[i].first==0)line[i]={a,0};
			else{
				sets[line[i].first].push_back({a,i});
				line[i]={line[i].first,a};
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y,ans=1e9;
		cin>>x>>y;
		vis[x]=true;
		bfs(x,y,w[x]+w[y],ans);
		vis[x]=false;
		cout<<ans<<"\n";
	}
	return 0; 
} 