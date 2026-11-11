#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>c>>b>>d;
    if(a==b)
        cout<<1;
    else
    {
        cout<<"0000"<<endl;
        return 0;
    }
    if(c[0]==d[0] && c[1]==d[1])
        cout<<1;
    else
    {
        cout<<"000"<<endl;
        return 0;
    }
    bool q=(c[2]<='C' && d[2]<='C'),w=(c[2]>='D' && d[2]>='D');
    if(q==1 || w==1)
        cout<<1;
    else
    {
        cout<<"00"<<endl;
        return 0;
    }
    if(w==1 || (q==1 && abs(int(c[2])-int(d[2]))==1))
        cout<<1<<endl;
    else
    {
        cout<<"0"<<endl;
        return 0;
    }
    return 0;
}

