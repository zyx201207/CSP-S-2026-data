#include<bits/stdc++.h>
using namespace std;
int pd(char a,char b)
{
    if((a<='C'&&b<='C')||(a>='D'&&b>='D'))
    {
        if((a=='A'&&b=='B')||(a=='B'&&b=='A')) return 2;
        if((a=='B'&&b=='C')||(a=='C'&&b=='B')) return 2;
        if((a=='D'&&b=='F')||(a=='F'&&b=='D')) return 2;
        return 1;
    }
    return 0;
}
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string c1,c2;
    int a,b;
    char c,d;
    cin>>c1>>a>>c>>c2>>b>>d;
    if(c1==c2) cout<<1;
    else cout<<0;
    if(c1==c2&&a==b) cout<<1;
    else cout<<0;
    if(c1==c2&&a==b&&pd(c,d)) cout<<1;
    else cout<<0;
    if(c1==c2&&a==b&&pd(c,d)==2) cout<<1;
    else cout<<0;
    cout<<"\n";



    return 0;
}
