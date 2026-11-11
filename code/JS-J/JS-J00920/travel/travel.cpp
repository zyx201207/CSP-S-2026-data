# include <bits/stdc++.h>
using namespace std ;

string c1,s1,c2,s2,a,b,c,d ;
int cc,dd ;

int main()
{
    freopen("travel.in","r",stdin) ;
    freopen("trevel.out","w",stdout) ;
    cin >> c1 >> s1 >> c2 >> s2 ;
    if (c1==c2 && c1!="01" && c1!="16"){
        cout << 1 ;
        a=s1.substr(0,2),b=s2.substr(0,2) ;
        if (a==b){
            cout << 1 ;
            c=s1[2],d=s2[2] ;
            if((c<="C" && d<="C") || (c>="D" && d>="D")){
                cout << 1 ;
                if (c=="A") cc=1 ;
                if (c=="B") cc=2 ;
                if (c=="C") cc=3 ;
                if (c=="D") cc=4 ;
                if (c=="F") cc=5 ;
                if (d=="A") dd=1 ;
                if (d=="B") dd=2 ;
                if (d=="C") dd=3 ;
                if (d=="D") dd=4 ;
                if (d=="F") dd=5 ;
                if (abs(cc-dd)==1) cout << 1 ;
                else cout << 0 ;
            }
            else cout << "00" ;
        }
        else cout << "000" ;
    }
    else cout << "0000" ;
    return 0 ;
}
