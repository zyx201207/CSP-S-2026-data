/*
后视镜里的世界
越来越远的告别
你转身向北
侧脸还是很美
我用眼光去追
竟听见你的泪
在车窗外面徘徊
是我错失的机会
你站的方位
跟我中间隔着泪
街景一直在后退
你的崩溃在窗外零碎
我一路向北
离开有你的季节
你说你好累
已无法再爱上谁
风在山路吹
过往的画面全都是我不对 
细数惭愧 
我伤你几回 
*/ 
#include<bits/stdc++.h>
//#define int long long
using namespace std;

const int N = 2e6+5;

struct Edge{
	int to, next;
}edge[N << 1];
int head[N], erty;

void addedge(int u, int v){
	edge[++erty] = {v, head[u]};
	head[u] = erty;
}

int c, t, n, d;
int x[N];

int vis[N], dis[N], cnt[N];

struct node{
	int u, dis;
	bool operator < (const node& oth) const{
		return dis > oth.dis;
	}
};

void dijkstra(int s){
	memset(cnt, 0, sizeof cnt);
	memset(vis, 0, sizeof vis);
	memset(dis, 0x3f, sizeof dis);
	priority_queue<node> q;
	q.push({s, 0});
	dis[s] = 0, cnt[s] = 1;
	
	while(!q.empty()){
		int u = q.top().u;q.pop();
//		if(vis[u])continue;
//		vis[u] = 1;
		for(int i = head[u]; i != 0; i = edge[i].next){
			int v = edge[i].to, w = 1;
			if(dis[v] == dis[u] + w)cnt[v] += cnt[u];
			if(dis[v] > dis[u] + w)dis[v] = dis[u] + w, cnt[v] = cnt[u], q.push({v, dis[v]});
		}
	}
}

namespace subtask1{
	void main(){
		while(t--){
			cin>>n>>d;
			for(int i = 1; i <= n; i++)cin>>x[i];
			sort(x+1, x+n+1);
			int ans = 0;
			for(int i = 1; i <= n; i++){
				for(int j = i+1; j <= n; j++){
					if(x[j]-x[i] >= 2*d)continue;
					else if(x[j]-x[i] <= d)continue;
					else{
						int lt = 0;
						for(int l = i; l <= j; l++){
							if(x[l]-x[i] <= d && x[j]-x[l] <= d)lt++;
							if(lt >= 3)break;
						}
						ans += (lt == 2 ? 1 : 0);
					}
				}
			}
			cout<<ans<<endl;
		}
	}
}


signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>c>>t;
	if(c == 13 || c == 14)return subtask1::main(), 0;
	while(t--){
		memset(edge, 0, sizeof edge);
		memset(head, 0, sizeof head);
		erty = 0; 
		cin>>n>>d;
		for(int i = 1; i <= n; i++)cin>>x[i];
		sort(x+1, x+n+1);
		for(int i = 1; i <= n; i++){
			for(int j = i+1; j <= n; j++){
				if(x[j]-x[i] > d)continue;
				addedge(i, j), addedge(j, i);
			}
		}
		int ans = 0;
		for(int i = 1; i <= n; i++){
			dijkstra(i);
			for(int j = i+1; j <= n; j++)if(cnt[j] == 2)ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
久未放晴的天空
依旧留着你的笑容
哭过 却无法掩埋歉疚
风筝在阴天搁浅
想念还在等待救援
我拉着线
复习你给的温柔
曝晒在一旁的寂寞
笑我给不起承诺
怎么会怎么会
你竟原谅了我
我只能永远读着对白
读着我给你的伤害
我原谅不了我
就请你当作我已不在
我睁开双眼看着空白
忘记你对我的期待
读完了依赖
我很快就离开 
*/
