//#include<bits/stdc++.h>
//using namespace std;
//
//const int M = 3e5+5;
//const int N = 5e5+5;
//
//int n, m, a[N];
//int cnt[M], ans[M];
//int vis[M], pos[M];
//
//map<int, map<int, int>> lst_ans;
//
//int fa[N];
//int find(int x){
//	return x == fa[x] ? fa[x] : fa[x] = find(fa[x]);
//}
//
//int addc[N];
//
//void dfs(int col){
//	vis[col] = 1;
//	int left_pos = pos[col]-1;
//	int left_col = a[left_pos];
//	if(!vis[left_col])dfs(left_col);
////	memcpy(lst_ans[col], lst_ans[left_col], sizeof lst_ans[col]);
//	for(int i = 1; i <= m; i++)lst_ans[col][i] = lst_ans[left_col][i];
//	lst_ans[col][col] = 1;
//	return ;
//}
//
//int main(){
//	freopen("card.in", "r", stdin);
//	freopen("card.out", "w", stdout);
//	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//	cin>>n>>m;
//	for(int i = 1; i <= n; i++)cin>>a[i], fa[i] = i;
//	reverse(a+1, a+n+1);
//	for(int i = 1; i <= n; i++){
//		if(vis[a[i]]){fa[i] = pos[a[i]];continue;}
//		vis[a[i]] = 1, pos[a[i]] = i;
//	}
//	memset(vis, 0, sizeof vis);
//	for(int i = 1; i <= n; i++)addc[fa[i]]++;
//	for(int i = 1; i <= m; i++)if(!vis[i])dfs(i);
//	
//	for(int i = 1; i <= m; i++)for(int j = 1; j <= m; j++)ans[j] += lst_ans[i][j]*addc[pos[i]];
//	for(int i = 1; i <= m; i++)cout<<ans[i]<<" \n"[i == m];
//	return 0;
//}

#include<bits/stdc++.h>
using namespace std;

const int M = 3e5+5;
const int N = 5e5+5;

int n, m, a[N];
vector<int> pos[M];

int find(int col, int np){
	for(auto i : pos[col])if(i > np)return i;
}

int vis[N], ans[N];

int lpos[M], addc[M];
void solve(int st){
	memset(vis, 0, sizeof vis);
	int lst_rest = st, cnt = 0;
	for(int i = st; i <= n; ){
		int nxt = find(a[i], i);
		if(nxt != n+1)i = nxt;
		else vis[a[i]] = 1, i++;
	}
	for(int i = 1; i <= m; i++)ans[i] += vis[i]*addc[a[st]];
//	cout<<cnt<<" ";
}


int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>n>>m;
	for(int i = 1; i <= n; i++)cin>>a[i], pos[a[i]].push_back(i), lpos[a[i]] = i;
	for(int i = 1; i <= m; i++)pos[i].push_back(n+1);
	for(int i = 1; i <= n; i++)addc[a[i]]++;
	for(int i = 1; i <= m; i++)solve(lpos[i]);
	
	for(int i = 1; i <= m; i++)cout<<ans[i]<<" \n"[i == m];
	return 0;
}


