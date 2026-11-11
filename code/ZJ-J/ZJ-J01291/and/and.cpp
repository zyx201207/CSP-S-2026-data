#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+5;

int n, m, a[N];
int ato2[N][35];
int sum2[35];

int nh[35][N], ncnt[35];

void dv(int pos, int x){
	for(int i = 0; i <= 30; i++){
		if(x&(1<<i))ato2[pos][i] = 1;
		else nh[i][++ncnt[i]] = pos;
	}
	for(int i = 0; i <= 30; i++)sum2[i] += ato2[pos][i];
}

int vis[N];
queue<int> q1, q2;
int ld, ret;

int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>n>>m;ret = n;
	for(int i = 1; i <= n; i++)cin>>a[i];
	sort(a+1, a+n+1, greater<int>());
	for(int i = 1; i <= n; i++)dv(i, a[i]);
	
	for(int i = 1; i <= n; i++)q2.push(i);
	for(int di = 30; di >= 0; di--){
		if(sum2[di] < m)continue;
		while(!q2.empty())q1.push(q2.front()), q2.pop();
		while(!q1.empty()){
			int u = q1.front();q1.pop();
			if(ato2[u][di])q2.push(u);
			else ret--;
			if(ret == m)break;
		}
		if(ret == m)break;
	}
	while(!q1.empty())q2.push(q1.front()), q1.pop();
	int ans = a[q2.front()];q2.pop();
	while(!q2.empty()){
		ans &= a[q2.front()];
		q2.pop();
	}
	cout<<ans;
	return 0;
}

