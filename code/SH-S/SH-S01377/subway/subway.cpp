#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 500005
ll c,n,m,d,q,w[N],k[505];
__int128 mp[505][505];
vector<pair<int,int>> e[N];
vector<pair<int,int>> sub[505];
void prnt(__int128 x){
	if(x > 10)
		prnt(x/10);
	cout << int(x%10);
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++)
		cin >> w[i];
	for(int i = 1;i <= n;i++){
		cin >> k[i];
		for(int j = 1;j <= k[i];j++){
			int v,ww;
			cin >> v >> ww;
			e[v].push_back({i,ww});
			sub[i].push_back({v,ww});
		}
	}
	memset(mp,0x3f,sizeof(mp));
	for(int i = 1;i <= n;i++){
		for(int j = 0;j < sub[i].size();j++){
			int mid = sub[i][j].first;
			int len1 = sub[i][j].second;
			for(int l = 0;l < e[mid].size();l++){
				int v = e[mid][l].first;
				ll len2 = e[mid][l].second;
				mp[i][v] = mp[v][i] = min(__int128(len2+len1),mp[i][v]);
			}
		}
	}
	for(int i = 1;i <= n;i++)
		mp[i][i] = 0;
	for(int l = 1;l <= n;l++){
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				if(mp[i][l]+mp[l][j] < mp[i][j])
					mp[i][j] = mp[i][l]+mp[l][j];
			}
		}
	}

	for(int i = 1;i <= q;i++){
		int x,y;
		__int128 mn = INT_MAX*INT_MAX*INT_MAX;
		cin >> x >> y;
		for(int j = 0;j < e[x].size();j++){
			for(int l = 0;l < e[y].size();l++){
				__int128 lenss = mp[e[x][j].first][e[y][l].first];
				mn = min(mn,__int128(w[x]+w[y]+lenss+e[x][j].second+e[y][l].second));
			}
		}
		prnt(mn);
		cout <<'\n';
	}
	return 0;
}
