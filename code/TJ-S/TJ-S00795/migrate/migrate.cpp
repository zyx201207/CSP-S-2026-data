#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> g[10001];
int x[10001],t[10001],dis[10001],inf = 1e8;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c,ti;
	cin >> c >> ti;
	while(ti--){
		int n,d,cnt = 0;
		cin >> n >> d;
		for(int i = 1;i<=n;i++){
			cin >> x[i];
			g[i].clear();
		}
		sort(x+1,x+n+1);
		for(int i = 1;i<=n;i++){
			for(int j = i+1;j<=n&&x[j]-x[i]<=d;j++){
                g[i].push_back(j);
			}
		}
		for(int i = 1;i<=n;++i){
			for(int j = 1;j<=n;++j){
                t[j] = 0;
                dis[j] = inf;
			}
			dis[i] = 0;
			for(int j = 1;j<=n;++j){
                for(int v:g[j]){
                    if(dis[j] + 1 < dis[v]){
                        dis[v] = dis[j] + 1;
                        t[v] = 1;
                    }
                    else if(dis[j] + 1 == dis[v]){
                        t[v] = t[j]+1;
                    }
                }
                if(t[j] == 2 && j>=i+d+1){
                    cnt++;
                }
            }
		}
		cout << cnt << "\n";
	}
	return 0;
}

