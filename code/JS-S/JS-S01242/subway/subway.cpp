#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int c,n,m,d,q;
const long long INF= LONG_LONG_MAX/2-5;

int x,y;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> q;
    vector<ll> w(m+1);
    vector< vector <ll> > a(n+1);
    vector< vector <ll> > t(n+1);

    vector< ll > k(n+1);
    long long sumk=0;
    long long a1,b1;
    for(int i =1 ; i<=m;i++){
        cin >> w[i];
    }
    for( int  i=1; i<=n;i++) {
        cin >> k[i];
        int aa = k[i];
        sumk+=aa;
        a[i].push_back(0);t[i].push_back(0);
        for(int j = 1; j <= k[i]; j++) {
            cin >> a1 >> b1;
            a[i].push_back(a1);t[i].push_back(b1);
        }
    }
    ll gsiz=m+sumk+5;
    vector< vector <ll> > g(gsiz);
    for ( int i = 0; i < gsiz; i++){
        for ( int j = 0; j < gsiz; j++) {
            g[i].push_back(INF);
        }

    }
    // for ( int i = 1; i <= m; i++) {
    //     g[i][m+i] = g[m+i][i] = w[i];


    // }
    long long cnt=m+1;
    for ( int i = 1; i <= n; i++ ) {
        for( int j = 1; j <= k[i]; j++) {
            // g[a[i][j]][cnt]=g[cnt][a[i][j]]=t[i][j];
            // g[cnt][cnt+1]=g[cnt+1][cnt]=0;
            // cnt++;

            // g[a[i][j]][a[i][j+1]]=g[a[i][j+1]][a[i][j]]
            //     =min(g[a[i][j]][a[i][j+1]],t[i][j]+t[i][j+1]);
            for ( int kk =1; kk<=k[i]-j; kk++) {
                g[a[i][j]][a[i][j+kk]]=g[a[i][j+kk]][a[i][j]]
                 =min(g[a[i][j]][a[i][j+kk]],t[i][j]+t[i][j+kk]);
            }
        }
        // int j = k[i];
        // g[a[i][j]][cnt]=g[cnt][a[i][j]]=t[i][j];
        // cnt++;
    }
    //cout << cnt << endl;

    // for(int k = 1; k < cnt; k++) {
    //     for ( int i = 1; i <cnt;i++){
    //         for(int j = 1; j < cnt; j++ ) {
    //             g[i][j]=g[j][i]=min(g[i][j],g[i][k]+g[k][j]);
    //         }
    //     }
    // }
    for(int k = 1; k <=m; k++) {
        for ( int i = 1; i <=m;i++){
            for(int j = 1; j <=m; j++ ) {
                g[i][j]=g[j][i]=min(g[i][j],g[i][k]+g[k][j]);
            }
        }
    }

    while(q--){
        cin>>x>>y;
        cout << (g[x][y]+w[x]+w[y])<<'\n';
    }

    // int needno[100005], cnt=0;
    // vector< pair<int,int > > qs;

    // while(q--){
    //     cin >> x >> y;
    //     qs.push_back({x,y});
    //     needno[cnt++]=x;
    // }
    // int lstpos=unique(needno,needno+q)-needno-1;
    // for(int i = 0; i < lstpos; i++) {
    //     priority_queue< pair<ll, int>, vector< pair<ll, int> >, greater< pair<ll,int> > >  q;
    //     q.push({0,needno[i]});
    //     while(!q.empty()) {

    //     }


    // }



    return 0;
}