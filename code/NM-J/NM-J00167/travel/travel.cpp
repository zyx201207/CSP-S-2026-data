#include<bits/stdc++.h>
using namespace std ;
int main()
{
    freopen( "travel.in" , "r" , stdin ) ;
    freopen( "travel.out" , "w" , stdout ) ;


    int ca , cb ;
    string sa,sb ;
    cin>>ca>>sa>>cb>>sb ;
    if( ca == cb ) cout<<"1";
    else{ cout<<"0000"; return 0 ; }

    if( ca == cb && sa[0]==sb[0] && sa[1] == sb[1] ) cout<<"1";
    else { cout<<"000"; return 0 ; }

    char weia , weib ;
    weia = sa[2] ;
    weib = sb[2] ;
    if ( ( ( weia == 'A' || weia == 'B' || weia == 'C' ) && ( weib == 'A' || weib == 'B' || weib == 'C'        ) ) ||            ( weia == 'D' || weia == 'F' ) && ( weia == 'D' || weia == 'F' )  )
    {
        cout<<"1";
        if( abs( weia - weib ) == 1 )
        {
            cout<<"1";
        }
        else
        {
            cout<<"0";
        }
    }
    else
    {
        cout<<"00" ;
    }

    return 0;
}
