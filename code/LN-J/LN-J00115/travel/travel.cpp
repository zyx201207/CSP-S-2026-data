#include<bits/stdc++.h>
using namespace std;
#define QwQ return 0;
int pd(char a)
{
    if(a<='C')return 1;
    if(a>='D')return 2;
}
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a!=c){
        cout<<"0000";
        QwQ;
    }
    int Felix,liangtiaoyu;
    Felix=(b[0]-'0')*10+b[1]-'0';
    liangtiaoyu=(d[0]-'0')*10+d[1]-'0';
    if(Felix!=liangtiaoyu){
        cout<<"1000";
        QwQ;
    }
    int sailuo=pd(b[2]),beiliya=pd(d[2]);
    if(sailuo!=beiliya){
        cout<<"1100";
        QwQ;
    }
    if(abs(b[2]-d[2])==1)
    {
        cout<<"1111";
        QwQ;
    }
    cout<<"1110";
    QwQ;
}
