#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
using namespace std;
const int MX=2e6+5;
int c, T;
int n, d, sum;
int head[MX], cnt;
int x[MX];
int inq[MX], dis[MX], t[MX], dis2[MX];
struct node{
	int to, nex;
}edges[MX*2];
void add(int u, int v) {
	edges[++cnt].to=v;
	edges[cnt].nex=head[u];
	head[u]=cnt;
}
void spfa(int s){
	memset(inq, 0, sizeof(inq));
	for(int i=1; i<=n; i++)  dis[i]=1e9;
	queue<int> q;
	q.push(s); inq[s]=true;
	dis[s]=0;
	while(!q.empty()) {
		int u=q.front();
		q.pop(); inq[u]=false;
		for(int e=head[u]; e; e=edges[e].nex) {
			int v=edges[e].to;
			if(dis[u]+1<dis[v]) {
				dis[v]=dis[u]+1;
				if(!inq[v]) {
					q.push(v);
					inq[v]=true;
				}
			}
		}
	}
}
void spfa2(int s){
	memset(inq, 0, sizeof(inq));
	memset(inq, 0, sizeof(inq));
	for(int i=1; i<=n; i++)  dis2[i]=1e9;
	queue<int> q;
	q.push(s); inq[s]=true;
	dis2[s]=0;
	while(!q.empty()) {
		int u=q.front();
		q.pop(); inq[u]=false;
		for(int e=head[u]; e; e=edges[e].nex) {
			int v=edges[e].to;
			if(dis2[u]+1<=dis2[v]) {
				dis2[v]=dis2[u]+1;
				if(dis[v]==dis2[v] ) {
			//		cout << s << ' ' << u << '-' << v <<'\n';
					t[v]++;
				} 
				if(!inq[v]) {
					q.push(v);
					inq[v]=true;
				}
			}
			
		}
	}
}
signed main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
	cin >> c >> T;
	while(T--) {
		memset(edges,0,sizeof(edges));
		int last=1, ans=0;
		cin >> n >> d;
		for(int i=1; i<=n; i++) {
			cin >> x[i];
		//	cout << last << ' ' << i<<'\n' ;
			while(x[i]-x[last]>d && last<=i) {
				last++;
			} 
			for(int j=last; j<=i; j++) {
				add(j, i);
			} 
		}
		for(int i=1; i<=n; i++){
			memset(t, 0, sizeof(t));
			spfa(i);
			spfa2(i);
			//cout << i << "-----------\n";
			for(int i=1; i<=n; i++){
				//cout << dis[i] << ' ' << dis2[i] << '\n';
				//cout << t[i] << ' ';
				if(t[i]==2 )  ans++;
			}
			//cout << '\n';
 		}
		cout << ans << '\n';
	}
    return 0;
}
