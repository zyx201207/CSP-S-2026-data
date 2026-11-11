#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,b;
    char ac[5],bc[5];
    cin>>a;
    for(int i=1;i<=3;i++)
        cin>>ac[i];
    cin>>b;
    for(int i=1;i<=3;i++)
        cin>>bc[i];
    if(ac[3]=='F')ac[3]='E';
    if(bc[3]=='F')bc[3]='E';
    if(a==b)
    {
        cout<<"1";
        if(ac[1]==bc[1] && ac[2]==bc[2])
        {
            cout<<"1";
            if(((ac[3]>='A'&&ac[3]<='C') && (bc[3]>='A'&&bc[3]<='C'))||((ac[3]=='D'||ac[3]=='E') && (bc[3]=='D'||bc[3]=='E')))
            {
                cout<<"1";
                if(ac[3]-bc[3]==1 || bc[3]-ac[3]==1)
                    cout<<"1";
                else
                    cout<<"0";
            }
            else
                cout<<"00";
        }
        else
            cout<<"000";
    }
    else
        cout<<"0000";
    return 0;
}
