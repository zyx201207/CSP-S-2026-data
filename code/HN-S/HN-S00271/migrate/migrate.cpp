#include<bits/stdc++.h>
#define int long long
using namespace std;

int c , t , n , d , a[2000005] , nxt[2000005] , st[2000005][22] , p[2000005];
long long ans;
struct node{
    int x , l , r;
};
vector<node> v;
void init(){
    for( int i = 1 ; i <= n ; i++ ) st[i][0] = nxt[i];
    for( int i = 1 ; i <= 21 ; i++ ){
        for( int j = 1 ; j <= n ; j++ ) st[j][i] = st[st[j][i - 1]][i - 1];
    }
}
int check(int x , int y){
  //  cout << x << " " << y << ":\n";
    for( int i = 21 ; i >= 0 ; i-- ){
        if( st[x][i] != st[y][i] ) x = st[x][i] , y = st[x][i];
    }
    x = nxt[x] , y = nxt[y];
    if(!x || !y || x != y) return 0;
    return x;
}
void solve(){
    //cout << "test:\n";
    cin >> n >> d;
    ans = 0;
    v.clear();
    for( int i = 1 ; i <= n ; i++ ) cin >> a[i] , nxt[i] = p[i] = 0;
    for( int i = n , j = n ; i >= 1 ; i-- ){
        while(a[j] - a[i] > d) j--;
        if(j != i) nxt[i] = j , p[i] = p[i + 1] + 1;
    }
    //for( int i = 1 ; i <= n ; i++ ) cout << nxt[i] << " ";
    //cout << "\n";
    init();
    for( int i = n - 2 ; i >= 1 ; i-- ){
        if(!nxt[i]||nxt[i] == i + 1) continue;
        int tmp = check(nxt[i] , nxt[i] - 1);
        if(!tmp) continue;
        if( nxt[i] == i + 2 ){
            v.push_back({i , tmp , n + 1});
            continue;
        }
        int Tmp = check(nxt[i] , nxt[i] - 2);
        if(!Tmp){
            v.push_back({i , tmp , n + 1});
            continue;
        }
        v.push_back({i , tmp , Tmp - 1});
    }
    reverse(v.begin() , v.end());
    for( int i = n - 2 , j = v.size() ; i >= 1 ; i-- ){
        if( j && v[j - 1].x == i ) j--;
        if( j == v.size() ) continue;
        if( i + p[i] < v[j].l ) continue;
        int L = v[j].l , R = v[j].r;
        R = min( R , n ) , R = min( R , v[j].l + p[v[j].l] );
        if( j + 1 < v.size() ) R = min( R , v[j + 1].l - 1 );
        ans += max(0LL , R - L + 1);
    }
    cout << ans << "\n";
}
void solve3(){
    cin >> n >> d;
    for( int i = 1 ; i <= n ; i++ ) cin >> a[i];
    int D = a[2] - a[1];
    if( D >= d ){
        cout << "0\n";
        return;
    }
    int s = ceil(d * 1.0 / D);
    cout << max(0LL , n - 2 * s + 1 ) << "\n";
}
signed main(){
    freopen("migrate.in" , "r" , stdin);
    freopen("migrate.out" , "w" , stdout);
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> c >> t;
    if( c == 11 || c == 12 ){
        while(t--) solve3();
        return 0;
    }
    while(t--) solve();
    return 0;
}
/*
6 4
-3 0 1 2 3 4
(1 , 4)
(1 , 5)
(1 , 6)
*/
