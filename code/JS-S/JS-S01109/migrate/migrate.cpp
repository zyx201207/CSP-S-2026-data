#include <bits/stdc++.h>
#define qi ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define int long long
#define MP(a,b) make_pair(a,b)
#define pb(x) push_back(x)
using namespace std;
typedef long long ll;
typedef long double ldb;
typedef pair<int,int> pii;
typedef pair<int,string> pis;
int c,t;
const int N = 5e3+3;
int n,m;
int a[N];
pii dist[N][N];
priority_queue <pii,vector<pii>,greater<pii> > pq;
void dijkstra(int s){
    pq.push(MP(0,s));
    dist[s][s]=MP(0,0);
    while(!pq.empty()){
        int x=pq.top().second;
        int w=pq.top().first;
        pq.pop();
        for(int i=1;i<=n;i++){
            if(abs(a[i]-a[x])>m)continue;
            //cout << s << ' ' <<  i  << ' ' << x << endl;
            //cout << dist[s][i].first << ' ' << dist[s][x].first << endl;
            if(i!=x&&i!=s){
                if(dist[s][i].first>dist[s][x].first+1){
                    dist[s][i].first=dist[s][x].first+1;
                    dist[s][i].second=1;
                    pq.push(MP(w+1,i));
                }
                else if(dist[s][i].first==dist[s][x].first+1){
                    dist[s][i].second++;
                    pq.push(MP(w+1,i));
                }
            }
            //cout << dist[s][i].second << endl;
            //cout << "------------" << endl;
        }
    }
}
signed main(){
    qi;
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> c >> t;
    while(t--){
        memset(dist,0x3f,sizeof(dist));
        cin >> n >> m;
        for(int i=1;i<=n;i++){
            cin >> a[i];
        }
        for(int i=1;i<=n;i++){
            dijkstra(i);
        }
        int cnt=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i!=j){
                    if(dist[i][j].second==2||dist[j][i].second==2){
                        //cout << i << ' ' << j << endl;
                        cnt++;
                    }
                }
            }
        }
        //cout << dist[1][4].second << endl;
        cout << cnt/2 << endl;
    }
    return 0;
}
