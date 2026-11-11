#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("travel.in","r",stdin);
    //freopen("travel.out","w",stdout);
    string a,b,c,d;
    string t1="",t2="";
    cin>>a>>b>>c>>d;
    if(a==c)
    {
        cout<<1;
    }
    else{
        cout<<"0000";
        return 0;
    }
    t1+=b[0]+b[1];
    t2+=d[0]+d[1];
    if(t1==t2)
    {
        cout<<1;
    }
    else{
        cout<<"000";
        return 0;
    }
    char c1,c2;
    c1=b[2];
    c2=d[2];

    for(int i=0;i<2;i++)
    {
        if(c1=='A'&&c2=='B')
        {
            cout<<"11";
            return 0;
        }
        if(c1=='A'&&c2=='C')
        {
            cout<<"10";
            return 0;
        }

        if(c1=='B'&&c2=='C')
        {
            cout<<"10";
            return 0;
        }
        if(c1=='D'&&c2=='E')
        {
            cout<<"11";
            return 0;
        }
        swap(c1,c2);
    }
    cout<<"00" ;
    return 0;
}
