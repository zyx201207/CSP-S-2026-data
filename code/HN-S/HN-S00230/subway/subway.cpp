#include<bits/stdc++.h>
#define forki for(int j = 1; j <= k[i]; j ++)
#define fori for(int i = 1; i <= n; i ++)
#define form for(int i = 1; i <= m; i ++)
#define forq for(int i = 1; i <= q; i ++)
#define Inter ios::sync_with_stdio(0);
#define I_am_HN_S00230 cout.tie(0);
#define int long long
#define core_CPU cin.tie(0);
#include<algorithm>
#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<cmath>
#include<queue>
#include<set>

using namespace std;
const int N = 2e4 + 5;
int c,n,m,d,q,w[N],a[500][N],t[500][N],k[N],x[N],y[N],son[500][N],father[500][N],transfer[N];
struct node{
	int subway,position,minute;
};


void bfs(int start,int end){
	queue<node> q;
	int minn = 1e9;
//	fori forki if(a[i][j] == x[i])q.push({i,start,w[start] + t[i][start]});
	while(!q.empty()){
		int tsubway = q.front().subway,tposition = q.front().position,tminute = q.front().minute;
		if(tposition == end)minn = min(minn,tminute);
		q.pop();
		fori{
			forki{
				if(a[i][j] == tposition && i == tsubway){
//					q.push({tsubway,father[i][a[i][j]],tminute});
//					q.push({tsubway,son[i][a[i][j]],tminute});
				}else{
//					q.push({i,father[i][a[i][j]],tminute + t[tsubway][t[i][a[i][j]]] + t[i][a[i][j]]});
//					q.push({i,son[i][a[i][j]],tminute + t[tsubway][t[i][a[i][j]]] + t[i][a[i][j]]});
				}
			}
		}
	}
	cout << minn << endl;
	return;
}


//bool fath(int station,int subway){
//	if(father[station][subway] == a[station][subway]) return 1;
//	else if(father[station][subway] == father[station][subway]) return 0;
//	else return fath(father[station][subway],subway);
//}
//bool yson(int station,int subway){
//	if(son[station][subway] == a[station][subway]) return 1;
//	else if(son[station][subway] == son[station][subway]) return 0;
//	else return yson(son[station][subway],subway);
//}


signed main(){
	Inter core_CPU
	I_am_HN_S00230
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	form cin >> w[i];
	fori {
	    cin >> k[i];
	    forki{
	        cin >> a[i][j] >> t[i][a[i][j]];
//	        inst[a[i][j]]++;
//	        if(j == k[i]) father[i][a[i][j]] = father[i][a[i][j]];
//	        else father[i][a[i][j]] = a[i][j - 1];
//	        if(j == 1) son[i][a[i][j]] = son[i][a[i][j]];
//	        else son[i][a[i][j-1]] = a[i][j];
	    }
	}
	bool ans = 1;
	forq{
		cin >> x[i] >> y[i];
		int aaa = 0,bbb = 0;
		for(int j = 1; j <= n; j ++){
			for(int l = 1; l <= k[j]; l ++){
				if(a[j][l] == x[i])aaa = j;
				if(a[j][l] == y[i])bbb = j;
			}
		}
		if(aaa == bbb){
			cout << w[x[i]] + w[y[i]] + t[aaa][x[i]] + t[aaa][y[i]];
		}
		else{
			int cal = 0;
			for(int i = 1; i <= k[1]; i ++){
				for(int j = 1; j <= k[2]; j ++){
					if(a[1][i] == a[2][j])transfer[++cal] = t[1][a[1][i]] + t[2][a[2][j]];
				}
				sort(transfer+1,transfer+cal+1);
				cout << w[x[i]] + w[y[i]] + t[aaa][x[i]] + t[aaa][y[i]] + transfer[1];
			}
		}
	}


	return 0;
}
