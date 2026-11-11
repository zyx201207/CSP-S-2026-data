#include<bits/stdc++.h>
using namespace std;
#define int long long

int CCF, n, m, d, q;

signed main()
{
   freopen ("subway.in", "r", stdin);
    freopen ("subway.out", "w", stdout); 
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> CCF >> n >> m >> d >> q;
    
    int w[m + 10], dis[n + 10][n + 10];
    vector <pair <int, int> > v[m + 10];
    

    for (int i = 1; i <= m; i ++) cin >> w[i];
    for (int i = 1; i <= n; i ++){
    	int k;
    	cin >> k;
    	for (int j = 1; j <= k; j ++)
    	{
    		int aa, tt;
    		cin >> aa >> tt;
    		
    		v[aa].push_back ({i, tt});
		}
	}

    
    for (int i = 1; i <= n; i ++) 
        for (int j = 1; j <= n; j ++)
            dis[i][j] = 1e18;
            
    for (int i = 1; i <= n; i ++) dis[i][i] = 0;
    
    for (int i = 1; i <= m; i ++)
        for (int j = 0; j < v[i].size(); j ++)
            for (int k = j + 1; k < v[i].size(); k ++)
                dis[v[i][j].first][v[i][k].first] = min (v[i][j].second + v[i][k].second, dis[v[i][j].first][v[i][k].first]); 
                
    for (int k = 1; k <= n; k ++)
        for (int i = 1; i <= n; i ++)
            for (int j = 1; j <= n; j ++)
                dis[i][j] = dis[j][i] = min (dis[i][j], dis[i][k] + dis[k][j]);
                
    while (q --)
    {
    	int x, y, ans = 1e18;
    	cin >> x >> y;
    	for (int i = 0; i < v[x].size(); i ++)
    	    for (int j = 0; j < v[y].size(); j ++)
    	        ans = min (ans, v[x][i].second + v[y][j].second + dis[v[x][i].first][v[y][j].first]);
    	        //枚举从几号地铁换到几号地铁 
    	        
    	cout << ans + w[x] + w[y] << endl;
	}
    
	return 0;
}
/*
                    CCCCCCCCCCC   CCCCCCCCCCC    FFFFFFFFFFF              N      N      BBBBBBB     
                    C             C              F                        NN     N      B     B
                    C             C              F                        N N    N      B     B
                    C             C              F                        N  N   N      BBBBBB
                    C             C              FFFFFFFFFFF              N   N  N      B     B
                    C             C              F                        N    N N      B     B
                    C             C              F                        N     NN      B     B
                    CCCCCCCCCCC   CCCCCCCCCCC    F                        N      N      BBBBBB
                    
                    
    i no chi ni ke re wa ra de ru. 
*/
