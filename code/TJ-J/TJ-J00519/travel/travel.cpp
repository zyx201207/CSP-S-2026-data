#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string rnum,rseat,xnum,xseat;
bool f1,f2,f3,f4;
bool check(char a,char b)
{
    if( (a=='D'&&b=='F')||(a=='F'&&b=='D') ) return true;
    else return false;
}
int main()
{//
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    cin>>rnum>>rseat>>xnum>>xseat;
    if(rnum==xnum) f1=true;
    if(rseat.substr(0,2)==xseat.substr(0,2))
    {
        f2=true;
        char g=rseat[2],t=xseat[2];
        if( (g>='A'&&g<='C'&&t>='A'&&t<='C')||(g>='D'&&g<='F'&&t>='D'&&t<='F')||(g>='D'&&g<='F'&&t>='D'&&t<='F')||(g>='A'&&g<='C'&&t>='A'&&t<='C') )
        {
            f3=true;
            if(abs(t-g)==1||check(g,t))
            {
                f4=true;

            }
        }

    }
    cout<<f1<<f2<<f3<<f4;
	return 0;
}
