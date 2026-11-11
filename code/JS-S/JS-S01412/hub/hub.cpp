#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 1e6 + 1e2;

int _,t,ans,len,c[MAXN];

vector<int> edges[MAXN];

bool b[MAXN],b2[MAXN];

int dist[MAXN];

inline void dfs2( int x ){
    for( auto i : edges[x] )
        if( !b2[i] ) b2[i] = true,dfs2( i );
}

inline void dfs( int x,int k,int n ){
    if( x == k + 1 ){
        for( int i = 1;i <= len;i++ ) b2[c[i]] = false;
        int cnt = 0;
        for( int i = 1;i <= len;i++ ){
            if( !b2[c[i]] ) cnt++,b2[c[i]] = true,dfs2( c[i] );
            if( cnt > 2 ) break;
        }
        //for( auto i : c ) printf( "%d ",i );
        //printf( "\n\n" );
        if( cnt > 2 ) return;
        queue<int> q;
        for( int i = 1;i <= n;i++ ) dist[i] = -1;
        for( int i = 1;i <= len;i++ ) q.push( c[i] ),dist[c[i]] = 0;
        int ma = -( 1 << 30 );
        while( !q.empty() ){
            int x = q.front();q.pop();
            for( auto i : edges[x] )
                if( dist[i] == -1 ) dist[i] = dist[x] + 1,ma = max( ma,dist[i] ),q.push( i );
        }
        for( int i = 1;i <= n;i++ ) if( dist[i] == -1 ) return;
        ans = min( ma,ans );
        return;
    }
    for( auto i : edges[x] )
        if( !b[i] ) b[i] = true,c[++len] = i,dfs( i,k,n ),b[i] = false,len--;
}

int main(){
    freopen( "hub.in","r",stdin );
    freopen( "hub.out","w",stdout );
    scanf( "%d%d",&_,&t );
    while( t-- ){
        int n,k;
        scanf( "%d%d",&n,&k ),len = 0,ans = 1 << 30;
        for( int i = 1;i <= n;i++ ) edges[i].clear(),b[i] = false,b2[i] = true;
        for( int i = 1,x,y;i < n;i++ ) scanf( "%d%d",&x,&y ),edges[y].push_back( x ),edges[x].push_back( y );
        for( int i = 1;i <= n;i++ ) edges[0].push_back( i );
        dfs( 0,k,n );
        printf( "%d\n",ans );
    }

    return 0;

}
/*
Made by LKK-0
I hope to make it AC
*/
