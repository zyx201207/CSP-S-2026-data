#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string  n1,n2;
    string m1,m2;
    cin>>n1>>m1>>n2>>m2;
    if(n1!=n2)
    {
        cout<<"0000";return 0;
    }
    else cout<<'1';
    long long k1=(m1[0]-'0')*10+m1[1]-'0',k2=(m2[0]-'0')*10+m2[1]-'0';
    if(k1==k2)
    {
        cout<<1;
    }
    else
    {
        cout<<"000";
        return 0;
    }
    if(m2[2]<='C'&&m1[2]<='C')
    {

        cout<<'1';
    }
    else if(m2[2]>'C'&&m1[2]>'C')
    {

        cout<<"11";
        return 0;
    }
    else {
        cout<<"00";
        return  0;
    }
    if(m1[2]-m2[2]==1||m1[2]-m2[2]==-1)
    {
        cout<<1;
    }
    else cout<<0;

    return 0;
}
