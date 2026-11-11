#include<bits/stdc++.h>

using namespace std;

#define ll long long

const int N = 2000050;

struct node{
	int ti, pos;
};

int c, t, n, d;
ll x[N];
int to[N], pos[3];

int ans = 0;

void bfs(int start){
	queue<node> q;
	q.push((node){0, start});
	int i = 0, cnt;
	while(!q.empty() && pos[2] <= n){
		cnt = 0;
		pos[1] = pos[2] = pos[0] = 0;
		while(!q.empty() && q.front().ti == i){
			node t = q.front();
			q.pop();
			cnt ++;
			if(t.pos > pos[0]) pos[2] = pos[1], pos[1] = pos[0], pos[0] = t.pos;
			else if(t.pos > pos[1]) pos[2] = pos[1], pos[1] = t.pos;
			else if(t.pos > pos[2]) pos[2] = t.pos;
			if(t.pos > n || t.pos < pos[0] - 8) continue;
			if(to[t.pos] <= 6){
				for(int i = 1; i <= 6; i ++)
					q.push({t.ti + 1, t.pos + max(0, to[t.pos] - i + 1)});
			}
			else{
				for(int i = 1; i <= 3; i ++)
					q.push({t.ti + 1, t.pos + i});
				for(int i = to[t.pos] - 2; i <= to[t.pos]; i ++)
					q.push({t.ti + 1, t.pos + i});
			}
		}
		i ++;
		if(i > 2 && cnt >= 3){
			ans += pos[1] - pos[2];
			if(pos[1] == pos[2]) break;
		}
		if(cnt >= 2 && to[pos[1]] == 0) break;
	}
}

void solve1(){
	while(t --){
		scanf("%d%d", &n, &d);
		for(int i = 1; i <= n; i ++)
			scanf("%lld", &x[i]);
		for(int i = 1; i <= n; i ++){
			for(int j = i + 1; j <= n; j ++){
				if(x[j] - x[i] <= d) to[i] = j - i;
				else break;
			}
		}
		for(int i = 1; i <= n; i ++)
			bfs(i);
		cout << ans << endl;
	}
}

void solve2(){
	while(t --){
		scanf("%d%d", &n, &d);
		for(int i = 1; i <= n; i ++)
			scanf("%lld", &x[i]);
		ll k = x[2] - x[1];
		if(k > d) cout << 0 << endl;
		else if(k * 2 > d) cout << 0 << endl;
		else if(k * 3 > d) cout << n - 3 << endl;
		else cout << 0 << endl;
	}
}

int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%d%d", &c, &t);
	if(c <= 10) solve1();
	else solve2();
	return 0;
}