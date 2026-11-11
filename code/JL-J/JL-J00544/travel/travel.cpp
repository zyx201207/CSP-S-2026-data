#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in",r,stdin);
    freopen("travel.out",w,stdout);
    int n,m;
    string n1,n2,m1,m2;
    cin>>n1>>n2>>m1>>m2;
    if(n1==m1)
    {
        cout<<1;
        if(n2[2]==m2[2])
        {
            cout<<1;
            if(!((n2[2]=='C'&&m2[2]=='D')||(n2[2]=='D'&&m2[2]=='C')))
            {
                cout<<1;
                n=(n2[0]-48)*10+n2[1]-48;
                m=(m2[0]-48)*10+m2[1]-48;
                if(max(n,m)-1==min(n,m))
                {
                    cout<<1;
                }
                else
                {
                    cout<<0;
                }
            }
        }
        else
        {
            cout<<0;
        }
    }
    else
    {
        cout<<0;
    }
    return 0;
}
