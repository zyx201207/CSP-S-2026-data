#include<bits/stdc++.h>
using namespace std;
int a,c,b1,b2,d1,d2;
string b,d;
bool f[5];
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>a>>b>>c>>d;
    if(a==c)
    {
        f[1]=1;
        b1=(b[0]-'0')*10+b[1]-'0';
        b2=b[2]-'A';if(b2==5) b2=4;
        d1=(d[0]-'0')*10+d[1]-'0';
        d2=d[2]-'A';if(d2==5) d2=4;
        if(b1==d1)
        {
            f[2]=1;
            if((b2<=2&&d2<=2)||(b2>=3&&d2>=3))
            {
                f[3]=1;
                if(abs(b2-d2)==1)
                    f[4]=1;
            }
        }
    }
    for(int i=1;i<=4;i++) cout<<f[i];
    cout<<'\n';
    return 0;
}
/*
02 01A 02 01B
1111

02 01C 02 01A
1110

02 01C 02 01D
1100


*/