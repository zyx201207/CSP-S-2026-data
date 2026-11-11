#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,b;
    char c[5],d[5];
    cin>>a;
    for(int i=1;i<=3;i++)
    {
        cin>>c[i];
    }
    cin>>b;
    for(int i=1;i<=3;i++)
    {
        cin>>d[i];
    }
    if(a==b)
    {
        cout<<"1";
        if(c[1]==d[1])
        {
            if(c[2]==d[2])
            {
                cout<<"1";
                if(c[3]==d[3])
                {
                    cout<<"00";
                    return 0;
                }

                else if(c[3]==d[3]+1||d[3]==c[3]+1)
                {
                    cout<<"11";
                    return 0;
                }
            }
            else{
                cout<<"000";
                return 0;
            }
        }
        else{
            cout<<"000";
            return 0;
        }
    }
    else
    {
        cout<<"0000";
        return 0;
    }
    return 0;
}
