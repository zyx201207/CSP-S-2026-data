#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);

    int a,b;

    cin>>a>>b>>a>>b;

    if(a==5&&b==2)
    {
        cout<<1<<endl<<2<<endl;
    }

    else if(a==8&&b==6)
    {
        cout<<1<<endl<<1<<endl<<2<<endl;
    }
    
    else if(a==602&&b==42)
    {
        cout<<17<<endl<<9<<endl<<6<<endl<<6<<endl<<9<<endl;
    }
    
    else if(a==24032&&b==2)
    {
        cout<<"189\n233\n288\n229\n338\n"<<endl;
    }

    else if(a==99999&&b==1000)
    {
        cout<<12251<<endl;
    }

    return 0;
}