#include<bits/stdc++.h>

using namespace std;

const int N = 1e5+10;
int w[N];
int k[510];
vector<pair<int,int>>G1[510];
vector<pair<int,int>>G2[N];


int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin >> c >> n >> m >> d >> q;
    for(int i = 1;i <= m;i++){
    	cin >> w[i];
	}
	for(int i = 1;i <= n;i++){
		cin >> k[i];
		for(int j = 1;j <= k[i];j++){
			int a,t;
			cin >> a >> t;
			G1[i].push_back({a,t});
			G2[a].push_back({i,t});
		}
	}
	while(q--){
		int x,y;
		cin >> x >> y;
		int ans = w[x]+w[y];
		int mn = N;
		for(auto i:G2[x]){
			for(auto j:G2[y]){
				if(i.first==j.first){
					mn=min(mn,i.second+j.second);
				}
			}
		}
		ans+=mn;
		cout << ans << endl;
	}
    return 0;
}
