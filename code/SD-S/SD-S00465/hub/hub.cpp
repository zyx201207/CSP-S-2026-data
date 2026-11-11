#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int c,t;
struct Node{
	int val,nxt;
}edge[200005];
int idx,head[100005],maxline[100005],line[100005],mid,cnt,n,k;
int subtree[100005];
int l = 0,maxstep = 0;
void add(int from,int to){
	edge[++idx].val = to;
	edge[idx].nxt = head[from];
	head[from] = idx;
}
void dfs(int x,int step,int fa){
	subtree[cnt] = max(subtree[cnt],step);
	for (int i = head[x];~i;i = edge[i].nxt){
		if (edge[i].val != fa)dfs(edge[i].val,step + 1,x);
	}
}
void dfs2(int x,int step,int fa){
	line[step] = x;
	if (step > maxstep){
		maxstep = step;
		l = x;
		for (int i = 0;i <= step;i ++) maxline[i] = line[i];
	}
	for (int i = head[x];~i;i = edge[i].nxt){
		if (edge[i].val != fa) dfs2(edge[i].val,step + 1,x);
	}
}
bool cmp(int x,int y){
	return x > y;
}
bool check(int p){
	int kp = k - 1;
	for (int i = 1;i <= cnt;i ++){
		kp -= max(0,subtree[i] - p);
		if (kp < 0) return 0;
	}
	return 1;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin >> c >> t;
	while (t --){
		l = 0,maxstep = 0;
		memset(head,-1,sizeof(head));
		memset(subtree,0,sizeof(subtree));
		memset(maxline,0,sizeof(maxline));
		cin >> n >> k;
		for (int i = 1;i < n;i ++){
			int u,v;cin >> u >> v;
			add(u,v);
			add(v,u);
		}
		dfs2(1,0,0);
		int r = l;
		dfs2(r,0,0);
		mid = maxline[maxstep / 2];
		cnt = 0;
		for (int i = head[mid];~i;i = edge[i].nxt){
			++cnt;
			dfs(edge[i].val,1,mid);
		}
		sort(subtree + 1,subtree + cnt + 1,cmp);
		int ll = 0,rr = subtree[1];
		while (ll < rr){
			int mid = (ll+rr) / 2;
			if (check(mid)) rr = mid;
			else ll = mid + 1;
		}
		cout << ll << '\n';
	}
	return 0;
}

