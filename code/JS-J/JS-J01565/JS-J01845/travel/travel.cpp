#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    string a,b,x,y;
    cin>>a>>b>>x>>y;
    if(a==x)
    {
        cout<<"1";
        if(b[0]==y[0]&&b[1]==y[1])
        {
            cout<<"1";
            char l1=b[2],l2=y[2];
            if(l1=='A')
            {
                if(l2=='B')
                {
                    cout<<"11";
                }
                else if(l2=='C')
                {
                    cout<<"10";
                }
                else
                {
                    cout<<"00";
                }
            }
            else if(l1=='B')
            {
                if(l2=='A'||l2=='C')
                {
                    cout<<"11";
                }
                else
                {
                    cout<<"00";
                }
            }
            else if(l1=='C')
            {
                if(l2=='A')
                {
                    cout<<"10";
                }
                else if(l2=='B')
                {
                    cout<<"11";
                }
                else
                {
                    cout<<"00";
                }
            }
            else if(l1=='D')
            {
                if(l2=='F')
                {
                    cout<<"11";
                }
                else
                {
                    cout<<"00";
                }
            }
            else
            {
                if(l2=='D')
                {
                    cout<<"11";
                }
                else
                {
                    cout<<"00";
                }
            }
        }
        else
        {

            cout<<"000";
        }
    }
    else
    {
        cout<<"0000";
    }
    return 0;
}
