#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=5e5+10,M=600;
map<int,int> vis;
int running_time=1e18;
vector<pair<int,int>> lines[M];//lines_i 经过的地铁站、 地铁站厅->lines_i的time 
int ans=0;
struct station{
	int w;//地铁口->站厅 time 
	vector<int> lines;//这个地铁站的线路 
	vector<int> t;//站厅->lines_i time 
}sta[N];
void dfs(int st,int end,int nowtime){
	if(st==end){
		running_time=min(running_time,nowtime);
//		cout<<running_time<<endl;
		return ;
	}
	for(int i=0;i<sta[st].lines.size();i++){
		for(auto s:lines[sta[st].lines[i]]){
			int a=s.first,t=s.second;
			if(vis[a]||a==st)continue;
			vis[a]=1;
//			cout<<st<<" "<<sta[st].lines[i]<<" "<<a<<endl;
			dfs(a,end,nowtime+sta[st].t[i]+t);
			vis[a]=0;
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c;
	int n,m,d,q;//地铁线路数  地铁站数  最多经过线路数  计划数 
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>sta[i].w;
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			sta[a].lines.push_back(i);
			sta[a].t.push_back(t);
			lines[i].push_back({a,t});
		}
	}
	while(q--){
		ans=0;
		running_time=1e18;
		vis.clear();
		int x,y;
		cin>>x>>y;
		ans=sta[x].w;
		dfs(x,y,0);
		ans+=sta[y].w;
		cout<<ans+running_time<<endl;
	}
	return 0;
}
/*
code by Ace
*/
