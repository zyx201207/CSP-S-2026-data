#include<bits/stdc++.h>
using namespace std;
#define N 1000009
int n,m,k,s,t,tmp,p[N],dep[N],h[N],a[N],b[N],buc[N],mx1[1009][1009],mx2[1009][1009],qwq[109][109][109];
vector<int> to[N];
bool vis[N];
void init(int u,int fa){
	p[u] = fa; dep[u] = dep[fa] + 1;
	for(int i = 0;i < to[u].size();i++){
		int v = to[u][i];
		if(v == fa) continue;
		init(v,u);
	}
}
void calc(int u,int fa){
	h[u] = 1; 
	for(int i = 0;i < to[u].size();i++){
		int v = to[u][i];
		if(vis[v] || v == fa) continue;
		calc(v,u);
		h[u] = max(h[u],h[v] + 1);
	}
	buc[h[u]]++; tmp = max(tmp,h[u]);
}
void solve1(){
	for(int i = 1;i <= m;i++){
		tmp = 0;
		for(int l = 0;l <= n;l++) buc[l] = 0;
		for(int j = i;j <= m && j - i + 1 <= k;j++){
			for(int l = 0;l <= k;l++) qwq[i][j][l] = n;
			calc(a[j],0);
			if(i == j) b[i] = tmp - 1;
			int pos = tmp,sum = 0;
			for(int l = j - i + 1;l <= k;l++){
				while(pos > 1 && sum + buc[pos] <= l - (j - i + 1)) sum += buc[pos],pos--;
				qwq[i][j][l] = pos - 1;
				// cout<<"qwq "<<i<<" "<<j<<" "<<l<<" "<<qwq[i][j][l]<<endl;
			}
		}
	}
	// for(int i = 1;i <= m;i++) cout<<b[i]<<" "; cout<<endl;
	for(int i = 1;i <= m;i++){
		for(int j = 1;j <= m;j++) mx1[i][j] = mx2[i][j] = 0;
		mx1[i][i] = b[i] + i;
		mx2[i][i] = b[i] - i;
		for(int j = i + 1;j <= m;j++){
			mx1[i][j] = max(mx1[i][j - 1],b[j] + j);
			mx2[i][j] = max(mx2[i][j - 1],b[j] - j);
		}
	}
	int ans = n;
	for(int i = 1;i <= m;i++)
		for(int j = i;j <= m && j - i + 1 <= k;j++)
			for(int l = j + 1;l <= m;l++)
				for(int r = l;r <= m && r - l + 1 + j - i + 1 <= k;r++){
					int mid = (j + l) >> 1,res = 0;
					if(j < mid) res = max(res,mx1[j + 1][mid] - j);
					if(mid + 1 < l) res = max(res,mx2[mid + 1][l - 1] + l);
					if(i > 1) res = max(res,mx2[1][i - 1] + i);
					if(r < m) res = max(res,mx1[r + 1][m] - r);
					for(int u = 0;u <= k;u++){
						int z = max(qwq[i][j][u],qwq[l][r][k - u]);
						ans = min(ans,max(res,z));
					}
				}
	cout<<ans<<endl;
}
int pre[N >> 3],suf[N >> 3],lg[N >> 3],st1[20][N >> 3],st2[20][N >> 3];
int qmx(int u,int l,int r){
	if(l > r) return -n;
	int p = lg[r - l + 1];
	return (u == 1 ? max(st1[p][l],st1[p][r - (1 << p) + 1]) : max(st2[p][l],st2[p][r - (1 << p) + 1]));
}
int qry(int l,int r,int u){ // [l,r] -> u
	return max(qmx(2,l,u) + u,qmx(1,u,r) - u);
}
void solve2(){
	for(int i = 1;i <= m;i++){
		tmp = 0; calc(a[i],0); b[i] = tmp - 1;
	}
	if(m <= 1000){
		for(int i = 1;i <= m;i++){
			for(int j = 1;j <= m;j++) mx1[i][j] = mx2[i][j] = 0;
			mx1[i][i] = b[i] + i;
			mx2[i][i] = b[i] - i;
			for(int j = i + 1;j <= m;j++){
				mx1[i][j] = max(mx1[i][j - 1],b[j] + j);
				mx2[i][j] = max(mx2[i][j - 1],b[j] - j);
			}
		}
		int ans = n;
		for(int j = 1;j <= m;j++)
			for(int l = j;l <= m;l++){
				int i = j,r = l;
				int mid = (j + l) >> 1,res = 0;
				if(j < mid) res = max(res,mx1[j + 1][mid] - j);
				if(mid + 1 < l) res = max(res,mx2[mid + 1][l - 1] + l);
				res = max(res,mx2[1][i] + i);
				res = max(res,mx1[r][m] - r);
				ans = min(ans,res);
			}
		cout<<ans<<endl;
		return;
	}
	for(int i = 1;i <= m;i++) st1[0][i] = b[i] + i,st2[0][i] = b[i] - i;
	for(int p = 1;p <= 19;p++)
		for(int i = 1;i + (1 << p) - 1 <= n;i++){
			st1[p][i] = max(st1[p - 1][i],st1[p - 1][i + (1 << p - 1)]);
			st2[p][i] = max(st2[p - 1][i],st2[p - 1][i + (1 << p - 1)]);
		}
	int pos = 1;
	for(int i = 1;i <= m;i++){
		while(pos < i && qry(1,i,pos) > qry(1,i,pos + 1)) pos++;
		pre[i] = qry(1,i,pos);
	}
	pos = n;
	for(int i = m;i >= 1;i--){
		while(pos > i && qry(i,n,pos) > qry(i,n,pos - 1)) pos--;
		suf[i] = qry(1,i,pos);
	}
	int ans = n;
	for(int i = 1;i < m;i++) ans = min(ans,pre[i] + suf[i + 1]);
	cout<<ans<<endl;
}
void solveA(){
	if(n / 2 >= k) cout<<(n / 2 - k + 7) / 4<<endl;
	else cout<<1<<endl;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	int C,T;
	cin>>C>>T;
	while(T--){
		cin>>n>>k;
		for(int i = 1;i <= n;i++) to[i].clear();
		for(int i = 1;i < n;i++){
			int u,v;
			cin>>u>>v;
			to[u].push_back(v);
			to[v].push_back(u);
		}
		init(1,0); s = max_element(dep + 1,dep + n + 1) - dep;
		init(s,0); t = max_element(dep + 1,dep + n + 1) - dep;
		m = 0;
		for(int i = 1;i <= n;i++) vis[i] = 0;
		for(int u = t;u;u = p[u]) a[++m] = u,vis[u] = 1;
		if(k == 1){
			cout<<dep[t] / 2<<endl;
			continue;
		}
		if(k == n){
			cout<<0<<endl;
			continue;
		}
		if(C == 13 || C == 14) solveA();
		else if(C == 7 || C == 11 || C == 12) solve2();
		else solve1();
	}
}
