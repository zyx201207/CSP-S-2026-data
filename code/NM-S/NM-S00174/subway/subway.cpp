#include<bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = (a); i <= (b); i ++ )
#define repf(i, a, b) for(int i = (a); i >= (b); i -- )
typedef long long ll;
const int N = 5e5 + 505;
int w[N],k[505];
vector<pair<int,int> > v[N+505];
struct node
{
    int u; ll dis;
    bool operator<(const node& B) const
    {
        return dis>B.dis;
    }
};
ll ds[N+505];
const ll inf = 0x3f3f3f3f3f3f3f3f;
ll D[N][22]; int cm[N][22]; int oz[N];
ll DDD[505][505];
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    int c,n,m,d,Q;cin>>c>>n>>m>>d>>Q;
    rep(i,1,m)cin>>w[i]; int tot=m;
    rep(i,1,n)
    {
        cin>>k[i]; tot ++;
        rep(j, 1, k[i])
        {
            int x, y; cin >> x >> y; cm[x][++oz[x]]=tot;
            v[tot].push_back({x, y}); v[x].push_back({tot, y});
            //cout<<tot<< ' ' << x<<endl;
        }
    }
//    rep(i,1,m)
//    {
//    	cout<<i<<endl;
//    	rep(j,1,oz[i]) cout << cm[i][j] << ' ';
//    	cout << endl;
//	}
    memset(D, 0x3f, sizeof D);
	
	memset(DDD, 0x3f, sizeof DDD);
//    rep(u, 1, m)
//    {
//    	int ou = v[u].size();
//    	rep(i, 0, ou - 1) rep(j, i, ou - 1)
//    	{
//    		int x=v[u][i].first-m; ll d1 = v[u][i].second;
//            int y=v[u][j].first-m; ll d2 = v[u][j].second;
//            DDD[x][y]=min(DDD[x][y], d1+d2); DDD[y][x] = DDD[x][y];
//		}
//	}
   // cout << tot << endl;
     rep(X, m+1, tot)
     {
         priority_queue<node> q; q.push({X, 0});
         rep(i,1,tot)ds[i]=inf; ds[X] = 0;
         while(!q.empty())
         {
             int u=q.top().u; ll dis=q.top().dis; q.pop();
             //cout<<u<<' '<<dis<<endl;
             if(dis!=ds[u]) continue;
             for(auto x:v[u])
             {
                 if(ds[x.first] > dis+x.second)
                 {
                     ds[x.first] = dis+x.second;
                     q.push({x.first, dis+x.second});
                 }
             }
         }
         rep(i,m+1,tot)
         {
         	DDD[X-m][i-m] = min(DDD[X-m][i-m], ds[i]);
         	DDD[i-m][X-m] = DDD[X-m][i-m];
	 	}
         //cout<<X<<endl;
         rep(i, 1, m) if(ds[i] != inf)
         {
         //	cout<<ds[i]<<' ';
             rep(j,1,oz[i])if(cm[i][j]==X)D[i][j]=ds[i];
         }
         //cout<<endl;
     }
    while(Q--)
    {
        int x, y;cin>>x>>y; ll dis=inf;
        rep(j, 1, oz[x])
        {
            rep(o, 1, oz[y]) {
            	//dis=min(dis,v[x][j-1].second+v[y][o-1].second+DDD[cm[x][j]-m][cm[y][o]-m]);
                dis=min(dis,D[x][j]+D[y][o]+DDD[cm[x][j]-m][cm[y][o]-m]);
            }
        }
        cout << dis + w[x] + w[y] << '\n';
    }
    return 0;
}
