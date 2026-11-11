#include<bits/stdc++.h>
using namespace std ;

unsigned long long countone( unsigned long long funcipt )
{
    unsigned long long ans = 0 ;
    while(funcipt)
    {
        //cout<<"inwhile"<<endl;
        if( funcipt % 2 == 1 )
        {
            ans ++ ;
        }
        funcipt /= 2 ;
    }
    return ans ;
}

int main()
{
    freopen( "and.in" , "r" , stdin ) ;
    freopen( "and.out" , "w" , stdout ) ;
    //cout<<countone(3)<<endl;
    unsigned long long n , m , a , mymax , mptr ;
    unsigned long long i , j ;
    cin>>n>>m ;
    vector<unsigned long long> d(n+5) ;
    vector<unsigned long long> ans(m+5) ;
    for( i = 1 ; i <= n ; i ++ )
    {
        //cout<<"in for1"<<endl;
        cin>>d[i];
    }

    mymax = countone( d[1] ) ;
    mptr = 1 ;
    for( i = 2 ; i <= n ; i ++ )
    {
        if(countone(d[i]) > mymax) {mymax = countone(d[i]) ; mptr = i;}
    }

    ans[1] = d[mptr] ;
    //cout<<"ans[1]="<<ans[1]<<endl;
    d[mptr] = 0 ;
    for( i = 2 ; i <= m ; i ++ )
    {
        //cout<<"inf3 i="<<i<<endl;
        mymax = 0 ;
        mptr = -1 ;
        for( j = 1 ; j <= n ; j ++ )
        {
            //cout<<"d["<<j<<"]="<<d[j]<<endl;
            //cout<<"s1="<<(ans[i-1] & d[j])<<endl;
            if( (ans[i-1] & d[j]) > (ans[i-1] & mymax) )
            {
                //cout<<"update"<<endl;
                mymax = d[j] ;
                mptr = j ;
            }
        }
        //cout<<mymax<<endl;
        d[mptr] = 0 ;
        ans[i] = ans[i-1]&mymax ;
    }
    cout<<ans[m]<<endl;
    //cout<<"BR"<<endl;
    return 0;
}
