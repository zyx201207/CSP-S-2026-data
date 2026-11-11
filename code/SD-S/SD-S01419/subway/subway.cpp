#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=505,M=5e5+505,inf=1e18,Ztsj=5e5;
int c,n,m,d,q,k;

namespace dijkpro{
	int a[M],u,v;
	vector<int> e[M],w[M],ne[N],nw[N];
	int dis[N];
	void find(int u){
		int v=0;
		for(int i=0;i<e[u+Ztsj].size();i++){
			v=e[u+Ztsj][i];
			if(v>Ztsj)continue;
			for(int j=0;j<e[v].size();j++){
				if(e[v][j]<=Ztsj||e[v][j]==u+Ztsj)continue;
				ne[u].push_back(e[v][j]-Ztsj);
				nw[u].push_back(w[u+Ztsj][i]+w[v][j]);
			}
		}
	}
	void initall(){
		for(int i=0;i<N;i++)dis[i]=inf;
	}
	struct node{
		int dis,pos;
		bool operator <(const node nd)const{
			return dis>nd.dis;
		}
	};
	priority_queue<node> pq;
	void dijkstra(int s){
		int u,v;
		initall();
		pq.push({0,s});
		dis[s]=0;
		while(pq.size()){
			u=pq.top().pos;
			pq.pop();
			int di=dis[u];
			for(int i=0;i<ne[u].size();i++){
				v=ne[u][i];
				if(dis[v]>dis[u]+nw[u][i]){
					dis[v]=dis[u]+nw[u][i];
					pq.push({dis[v],v});
				}
			}
		}
		return;
	}
	int query(int x,int y){
		int res=inf;
		for(int i=0;i<e[x].size();i++){
			if(e[x][i]<=Ztsj)continue;
			dijkstra(e[x][i]-Ztsj);
			for(int j=0;j<e[y].size();j++){
				if(e[y][j]<=Ztsj)continue;
				res=min(res,w[x][i]+dis[e[y][j]-Ztsj]+w[y][j]);
			}
		}
		return res+a[x]+a[y];
	}
	void solve(){
		for(int i=1;i<=m;i++)cin>>a[i];
		for(int i=1;i<=n;i++){
			cin>>k;
			for(int j=1;j<=k;j++){
				cin>>u>>v;
				e[i+Ztsj].push_back(u);
				w[i+Ztsj].push_back(v);
				e[u].push_back(i+Ztsj);
				w[u].push_back(v);
			}
		}
		for(int i=1;i<=n;i++)find(i);
		
//		for(int i=1;i<=n;i++){
//			for(int j=0;j<ne[i].size();j++)cout<<ne[i][j]<<' '<<nw[i][j]<<'|';
//			cout<<'\n';
//		}
		
		for(int i=1;i<=q;i++){
			int x,y;
			cin>>x>>y;
			cout<<query(x,y)<<'\n';
		} 
	}
}

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	dijkpro::solve();
	return 0;
}
/*

luogu user 667452 hu guan pls

<shi mo ge zhe>

wo yi ran zai wu ren wen jin de yin yu mei shi zhi di
he zhe yu yin chang zhe mei you ting zhong de ge qu
ren chao reng shi man wu mu di de xiang mu di di san qu
mang lu zhe wu wei zhe ji xu

qi qiu zhe shui neng gou jiang wo de xin fang qing qing kou ji
ji shi shi ni ye jin jin zhu zu le pian ke bian li qu
xiang zhe huo xu xia ge lu kou hui you shui yu wo xiang yu
na pa zhi yi shun de qi ji

<dong jing bu tai re>

ding ding dang dang QQ xiang qi hui shi shui ne Nayo
hui shi ta ma Nayo
shen me shi ne Ayo

jia zhuang zheng jing bang ta ba shi qing dou bai ping Nayo
bu duo liao le Nayo
qu chi fan le Ayo

xin li ming ming hen xi huan que bao chi zhe ju li
o pa bei shang hai jiu wei zhuang chu gao leng de biao qing
yi wei zhe yang zong you yi tian ta hui jie jin ni
zhi dao na tian kan jian ta he bie ren zai yi qi

总之是释怀了吧

这次CSP也是没招了，T2死活调不出来，T3想半天对不了一点，然后T4雷霆没做完，T1正确性存疑 

T2 这个 跑最大的5秒我真服了，我这常数卡不了一点啊啊 

*/


