#include<bits/stdc++.h>
using namespace std ;
int main()
{
    freopen( "card.in" , "r" , stdin ) ;
    freopen( "card.out" , "w" , stdout ) ;

    long long n , m , a , i , j , k , w ;
    bool isbreak ;
    cin>>n>>m ;
    vector<long long> cds(n+5) ;
    vector<long long> dsk;
    vector<long long> ans(m+5) ;
    for( i = 1 ; i <= n ; i ++ )
    {
        cin>>cds[i] ;
    }

    for( i = 1 ; i <= n ; i ++ ) // playing
    {
        //cout<<"infor i="<<i<<endl;
        dsk.clear() ;
        //dsk.push_back(-1) ;
        for( j = i ; j <= n ; j ++ )
        {
            for( k = 0 ; k < dsk.size() ; k ++ )
            {
                if( dsk[k] == cds[j] )
                {
                    while( dsk.size() != k-1 && !dsk.empty() )
                        dsk.pop_back();
                    break ;
                }
            }
            //cout<<"after del,j="<<j<<endl;
            //cout<<"size="<<dsk.size()<<endl;
            dsk.push_back( cds[j] ) ;
        }
        //cout<<"after play,i="<<i<<endl;
        //cout<<"size="<<dsk.size()<<endl;
        for( j = 1 ; j <= m ; j ++ )
        {
            isbreak = false;
            for( k = 0 ; k < dsk.size() ; k ++ )
            {
                if( dsk[k] == j )
                {
                    ans[j] ++ ;
                    isbreak = true ;
                    break ;
                }
            }
            if(isbreak)
            {
                continue ;
            }
            if( cds[i] == j )
            {
                ans[j] ++ ;
            }
        }
    }

    for( i = 1 ; i <= m ; i ++ )
    {
        cout<<ans[i]<<' ';
    }

    return 0 ;
}
