#include<bits/stdc++.h>
using namespace std;

int c,n,m,d,q;
int w[150000];
int t[510][500010];
int zhantai[500010];

vector<pair<int,int>> subs[510];

int minc = 0x3f3f3f3f;

void dfs(pair<int,int>ci, int end, int cost){
	if(ci.second == end){
		minc = min(minc,cost);
		return;
	}
	
	if(cost > minc) return;
	for(pair<int,int> i : subs[ci.second]){
		dfs(i, end, cost+ t[ci.first][i.first] + t[i.first][i.first]);
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++){
		cin >> w[i];
	}
	for(int i = 1; i <= n; i++){
		int ai;
		cin >> ai;
		int a1;
		for(int j = 1; j <= 4; j++){
			if(j % 2 == 1){
				if(j == 1){
					cin >> a1;
				}else{
					int a2;
					cin >> a2;
					subs[a1].push_back({i, a2});
					zhantai[a1] = i;
				}
			}else{
				cin >> t[i][j/2];
			}
		}
	}
	
	
	while(q > 0){
		q--;
		
		int xr,yr;
		cin >> xr >> yr;
		
		dfs({zhantai[xr],xr},yr,0);
		cout << w[xr] + w[yr] + t[xr][xr] + minc - t[yr][yr] << '\n';
	}
    
    return 0;
}
