#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, q, wi[500005],lssz[25],vis[505],qd,zd;
long long ans=0x3f3f3f3f3f;
int zt[505][25];
struct node{
    int line, point;
};
vector<node> v[500005];
void dfs(node w,int z,long long step){
	if(w.point==zd){
    	//cout << "jilu\n";
        ans = min(ans, step+wi[qd]+wi[zd]+zt[w.point][w.line]);
        return;
    }
	if(vis[w.point])return;
	else if(step+wi[qd]+wi[zd]>ans)return;
	vis[w.point]=1;
    for(auto u:v[w.point]){
    	//cout << "cong" << w.point << "zoudao" << u.point << " line:" << u.line <<" step:";
        if(u.line==w.line){
        	//cout << step << "\n";
            dfs(u, z, step);
        }else{
            int bxf = zt[w.point][u.line] + zt[w.point][w.line];
            //cout << step+bxf << "\n";
            dfs(u, z, step + bxf);
        }
    }
    vis[w.point]=0;
    //cout << "------------------\n";
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m;i++){
        cin >> wi[i];
    }
    for (int i = 1; i <= n;i++){
        int pop;
        cin >> pop;
        for (int j = 1; j <= pop;j++){
            int x,y;
            cin >> x >> y;
            //cout << "duqu" << x << " " << y << endl;
            lssz[j] = x;
            for (int u = 1; u <= j - 1;u++){
            	//cout << "lianjie" << lssz[u] << " " << x << " line:" << i << endl;
                v[lssz[u]].push_back({i,x});
                v[x].push_back({i,lssz[u]});
            }
            zt[x][i] = y;
        }
    }
    for (int i = 1; i <= q;i++){
        cin >> qd >> zd;
        memset(vis,0,sizeof(vis));
        dfs({0,qd}, zd, 0LL);
        cout << ans << endl;
    }
    /*for(int i=1;i<=m;i++){
    	for(auto y:v[i]){
    		cout << "point:" << y.point << " line:" << y.line << "  ";
		}
		cout << endl;
	}*/
    return 0;
}
