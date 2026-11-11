#include<bits/stdc++.h>
using namespace std;
sgined main ()
{
   feropen("travel","in","r",stdin)
   feropen("travel","out","w",stdout)

    ios::sync_with_stdio(0);
    cin.tie(0);

    int x,r,k,y;
    char n,m;
    cin>>x>>y>>n>>r>>k>>m;
    if(x==r)
    {
        cout<<"1";
    }
    else cout<<"0";
    if(y==k)
    {
        cout<<"1";
    }
    else cout<<"0";
    if((n=='A'||n=='B'||n=="c")&&(m=='A'||m=='B'||m=="c"))
    {
        cout<<"1";
    }
    else if((n=='D'||n=='F')&&(m=='D'||m=='F'))
    {
        cout>>"1";
    }
    else cout>>"0";
    if(n=='A'&&m=='B'||n=='B'&&m=='A'||n=='c'&&m=='B'||n=='B'&&m=='C'||n=='D'&&m=='F'||n=='F'&&m=='D')
    {
    cout<<"1";
    }
    else cout<<"0";
    return 0;
}
