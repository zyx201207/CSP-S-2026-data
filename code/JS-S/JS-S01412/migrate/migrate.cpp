#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 2e6 + 1e2;

int c,t,n;

ll d,a[MAXN];

pair<ll,ll> f[5010][5010];

int main(){
    freopen( "migrate.in","r",stdin );
    freopen( "migrate.out","w",stdout );
    scanf( "%d%d",&c,&t );
    while( t-- ){
        scanf( "%d%lld",&n,&d );
        for( int i = 1;i <= n;i++ ) scanf( "%lld",&a[i] );
        if( n <= 5000 ){
            for( int i = 1;i <= n;i++ )
                for( int j = 1;j < i;j++ )
                    if( a[i] - a[j] <= d ) f[i][j].first = 1,f[i][j].second = 1;
                    else f[i][j].first = 1LL << 60,f[i][j].second = 0;
            for( int i = 1;i <= n;i++ )
                for( int j = 1;j < i;j++ )
                    for( int k = j + 1;k < i;k++ )
                        if( f[k][j].first + f[i][k].first < f[i][j].first )
                            f[i][j].first = f[k][j].first + f[i][k].first,
                            f[i][j].second = f[k][j].second * f[i][k].second;
                        else if( f[k][j].first + f[i][k].first == f[i][j].first )
                            f[i][j].second += f[k][j].second * f[i][k].second;
            int cnt = 0;
            for( int i = 1;i <= n;i++ )
                for( int j = 1;j < i;j++ )
                    if( f[i][j].second == 2 ) cnt++;
            printf( "%d\n",cnt );
            continue;
        }

        bool ok = true;
        for( int i = 2;i < n && ok;i++ )
            if( a[i + 1] - a[i] != a[i] - a[i - 1] ) ok = false;
        if( ok ){
            int x = a[2] - a[1],y = d / x;
            ll ans = 0;y++;
            for( int i = 1;i < y;i++ )
                if( i + y < n ) ans += n - i - y + 1;
            printf( "%lld\n",ans );
            continue;
        }
        puts( "0" );
    }

    return 0;

}
/*
Made by LKK-0
I hope to make it AC
*/
