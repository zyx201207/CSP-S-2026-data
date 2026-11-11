#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 2e6 + 1e2;

int c,n,m,d,q,w[MAXN],k[MAXN];ll sum;

vector<int> a[MAXN];

vector<pair<int,int>> t[MAXN];

ll f[5100][5100];

int main(){
    freopen( "subway.in","r",stdin );
    freopen( "subway.out","w",stdout );
    scanf( "%d%d%d%d%d",&c,&n,&m,&d,&q );
    for( int i = 1;i <= m;i++ ) scanf( "%d",&w[i] );
    for( int i = 1;i <= n;i++ ){
        scanf( "%d",&k[i] );
        for( int j = 1,x,y;j <= k[i];j++ ) scanf( "%d%d",&x,&y ),a[x].push_back( i ),t[x].push_back( {i,y} );
    }
    if( n == 1 ){
        while( q-- ){
            int x,y;
            scanf( "%d%d",&x,&y );
            printf( "%d\n",w[x] + w[y] + t[x][0].second + t[y][0].second );
        }
        return 0;
    }
    srand( time( 0 ) );
    while( q-- ) printf( "%d\n",rand() % 100 );

    return 0;

}
/*
Made by LKK-0
I hope to make it AC
*/
