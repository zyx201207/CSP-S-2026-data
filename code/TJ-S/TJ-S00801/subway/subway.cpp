#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
typedef pair<int, int> PII; //first±ß second±àºÅ 
int w[N];
int sta[N];
int h[N], e[N], ne[N], c2[N], idx;
int dis[N];
int vis[N];

void add(int a, int b, int c1){
	e[idx]=b; c2[idx]=c1; ne[idx]=h[a]; h[a]=idx++;
}

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for(int i=1; i<=m; i++){
		int w1;
		cin >> w1;
		w[i]=w1;
	}
	vector<vector<int> > path(m+1, vector<int>(m+1));
	vector<vector<int> > times(m+1, vector<int>(m+1));
	for(int i=1; i<=n; i++){
			int all;
			cin >> all;
			sta[i]=all;
		for(int j=0; j<2*sta[i]; j++){
			int station;
			cin >> station;
			path[i].push_back(station);
			int time;
			cin >> time;
			times[station][i]=time;
			times[i][station]=time;
		}
	}
	int cnt[m+1];
	memset(cnt, 0, sizeof(cnt));
	memset(h, -1, sizeof(h));
	for(int i=1; i<=n; i++){
		for(int j=0; j<sta[i]-1; j++){
			cnt[path[i][j]]++;
			if(cnt[path[i][j]]!=1){
				int a=path[i][j];
				int b=path[i][j+1];
				int c3=times[i-1][j]+times[j][i];
				add(a, b, c3);
				add(b, a, c3);
			}else{
				int a=path[i][j];
				int b=path[i][j+1];
				int c3=0;
				add(a, b, c3);
				add(b, a, c3);
			}
		}
	}
	for(int i=1; i<=q; i++){
		int result=0;
		int x, y;
		cin >> x >> y;
		memset(dis, 0x3f3f3f3f, sizeof(dis));
		priority_queue<PII, vector<PII>, greater<PII> > q;
		dis[x]=0;
		q.push(make_pair(0, 1));
		while(!q.empty()){
			PII u=q.top();
			q.pop();
			int d=u.first;
			int v=u.second;
			if(vis[v]==1) continue;
			for(int j=h[v]; j!=-1; j=ne[j]){
				int z=e[j];
				if(dis[z]>d+c2[j]){
					dis[z]=d+c2[j];
					q.push(make_pair(dis[z], z));
				}
			}
			vis[v]=1;
		}
		result+=dis[y];
		result+=w[x]+w[y];
		cout << result << endl;
	}
	
	return 0;
}
