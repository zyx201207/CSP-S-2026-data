#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 1e6 + 1e2;

int n,ans;

ll m,a[MAXN],c;

int main(){
    freopen( "crystal.in","r",stdin );
    freopen( "crystal.out","w",stdout );
    scanf( "%d%lld",&n,&m );
    for( int i = 1;i <= n;i++ ) scanf( "%lld",&a[i] );
    sort( a + 1,a + n + 1 );
    int i = n,j = n;
    for( ;j;j-- )
        if( c + a[i] - a[j] <= m ) c += a[i] - a[j];
        else break;
    ans = max( ans,i - j ),i--;
    //printf( "%d ",c );
    //printf( "%d\n",j );
    for( ;i;i-- ){
        c -= ( a[i + 1] - a[i] ) * ( i - j );
       // printf( "%d\n",c );
        for( ;j;j-- )
            if( c + a[i] - a[j] <= m ) c += a[i] - a[j];
            else break;
 //       printf( "%d\n",c );
  //      printf( "%d\n",ans );
        ans = max( i - j,ans );
    }
    printf( "%d\n",ans );

    return 0;

}
/*
T : O( n )
S : O( n )
Algorithm : Two-pointers
Made by LKK-0
I hope to make it AC
*/
