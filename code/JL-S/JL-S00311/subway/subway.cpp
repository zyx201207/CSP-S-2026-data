#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.in","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    int w1,w2,w3,w4,wm;
    cin>>w1>>w2>>w3>>w4>>wm;
    int ki,ai1,ti1,ai2,ti2,aiki,tiki;
    cin>>ki>>ai1>>ti1>>ai2>>ti2>>aiki>>tiki;
    int fi,si1,pi1,si2,pi2,sifi,pifi;
    cin>>fi>>si1>>pi1>>si2>>pi2>>sifi>>pifi;
    int xr,yr;
    cin>>xr>>yr;
    int hr,gr;
    cin>>hr>>gr;







    int ans=0;


    if(xr=wm)
    {
        ans=wm+tiki;
    }
    if(yr!=tiki)
    {
        ans+ti2+ti2+tiki+1+yr;
    }


    cout<<ans;


    int bns=0;

    if(hr=wm)
    {
        bns=wm+pifi;
    }

    if(gr!=pifi)
    {
        bns+pir+pir+pifi+1+gr;
    }
    cout<<bns;

    return 0;
}
