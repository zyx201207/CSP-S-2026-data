#include<bits/stdc++.h>
using namespace std ;
class grch
{
public:
    unsigned long long num ;
    char ch ;
    //grch(){ num=0; ch='!' ; }
};

int main()
{
    freopen( "string.in" , "r" , stdin ) ;
    freopen( "string.out" , "w" , stdout ) ;

    unsigned long long n , a , hn , nhn = 0 ;
    unsigned long long ans = 0 , i , j ;
    grch tp ;
    char ic ;
    vector<grch> ipt , frt ;
    cin>>n;
    for( i = 0 ; i < n ; i ++ )
    {
        cin>>a>>ic ;
        nhn += a ;
        //cout<<"input part, a="<<a<<endl;
        tp.num = a ;
        tp.ch = ic ;
        ipt.push_back( tp ) ;
        //cout<<ipt[0].num<<endl;
    }
    hn = nhn / 2 ;
    j = hn;
    //cout<<ipt[0].num<<endl;
    //cout<<"For2 start"<<endl;
    for( i = 0 ; i < n ; i ++ )
    {
        //cout<<"ipt[0].num="<<ipt[0].num<<endl;
        //cout<<"ipt["<<i<<"].num="<<ipt[i].num<<endl;
        if( ipt[i].num <= j )
        {
            //cerr<<"IN For2 If1.if"<<endl;
            //cout<<"ipt["<<i<<"].num="<<ipt[i].num<<endl;
            //cerr<<ipt[i].num<<endl;
            j-= ipt[i].num ;
            frt.push_back(ipt[i]);
            //cerr<<ipt[i].num<<endl;
        }
        else
        {
            if(j == 0 )
            {
                break ;
            }
            else
            {
                tp.num = j ;
                tp.ch = ipt[i].ch ;
                frt.push_back(tp) ;
            }
        }
    }
    //cout<<"For2 stop"<<endl;
    j = hn ;
    tp.num = 0 ;
    unsigned cuptr=0;

    //*************
    //cout<<frt[0].num<<' '<<frt[0].ch<<endl;
    //cout<<frt[1].num<<' '<<frt[1].ch<<endl;
    //*************

    for( i = ipt.size() - 1 ; j > 0 ; i -- )
    {
        //cout<<"In For3"<<endl;
        //cout<<"j="<<j<<endl;
        while(true)
        {
            if(tp.num == 0)
                tp = frt[cuptr++] ;
            if( ipt[i].num <= tp.num )
            {
                //cout<<"For3 If2.true"<<endl;
                if( ipt[i].ch != tp.ch )
                {
                    ans += min(ipt[i].num ,j) ;
                    //cout<<"case1 ans+="<<min(ipt[i].num,j)<<endl;
                }
                if( j >= ipt[i].num )
                    j -= ipt[i].num ;
                else
                    j = 0;
                tp.num -= ipt[i].num ;
                break ;
            }
            else
            {
                //cout<<"in else"<<endl;
                //cout<<"ipt["<<i<<"].ch="<<ipt[i].ch<<endl ;
                //cout<<"tp.ch"<<tp.ch<<endl ;
                if( ipt[i].ch != tp.ch )
                {
                    ans += min(tp.num,j) ;
                    //cout<<"case2 ans+="<<min(tp.num,j)<<endl;
                }
                ipt[i].num -= tp.num ;
                if( j >= tp.num )
                    j -= tp.num ;
                else
                    j = 0 ;
                tp.num = 0 ;
            }
        }
    }

    cout<<ans ;

    return 0;
}
