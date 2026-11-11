#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//const int TM = 2e60;
const int MAXN = 5e5+5;
int c,n,m,d,q;
int w[MAXN];
struct Node{
	vector<pair<int,int>> tow;//通向 站点编号 所属线路 
	int wa[505];//变线花费为wa[i] 
}stat[MAXN];//站点编号 
struct Pos{
	int s;
	int p;//站点，线路  0代表地面 
	int timee;//时间 
};
bool vis[MAXN];
int bfs(int x,int y){
	queue<Pos> q;
	Pos c;
	c.p=0;
	c.s=x;
	c.timee = 0;
	q.push(c);
//	int total=TM;
	int total=0;
	while(!q.empty()){
		Pos now = q.front();
		q.pop();
		vis[now.s] = 1;
//		cout<<now.s<<' '<<now.p<<' '<<now.timee<<endl;
		if(now.s == y){
//			total=min(total,now.timee);
			total = now.timee;
			total += stat[now.s].wa[now.p];
//			cout<<stat[now.s].wa[now.p]<<endl;
			break;
		}
//		cout<<now.s<<' '<<now.p<<' ';
		for(auto& nex :stat[now.s].tow){//下一站 
			int todec = nex.first;//下一站编号 
			int tonum = nex.second;//下一站线路 
			if(vis[todec])continue;
			Pos nnow;
			nnow.p = tonum;
			nnow.s = todec;
			nnow.timee = now.timee;
			if(tonum != now.p){
				nnow.timee += stat[now.s].wa[now.p];
				nnow.timee += stat[now.s].wa[tonum];
				cout<<now.s<<' '<<now.p<<' '<<tonum<<endl;
			}
			q.push(nnow);
		}
	}
	return total;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
		
	}
	for(int i=1;i<=n;i++){//1到n号线 
		int k;
		cin>>k;
		int prev=0;
		int prevti=0;
		for(int j=1;j<=k;j++){//第i条线路 
			int x,t;
			cin>>x>>t;
			if(j!=1){//站点联通 
				pair<int,int> tmp;
				tmp.first = prev;
				tmp.second = i; 
				stat[x].tow.emplace_back(tmp);
				tmp.first = x;
				stat[prev].tow.emplace_back(tmp);
			}
			stat[x].wa[i] = t;
			prev=x;
			prevti=t;
		}
	}
	while(q--){
		memset(vis,0,sizeof(vis));
		int x,y;
		cin>>x>>y;
		int ans=0;
		ans+=w[x]+w[y];
		cout<<ans<<endl;
		int ti = bfs(x,y);
		ans+=ti;
		cout<<ans<<endl;
	}
	return 0;
}
