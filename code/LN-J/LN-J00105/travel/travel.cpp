#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel,out","w",stdout);
    int n,m;
    string n1,m1;
    cin>>n>>n1>>m>>m1;
    if(n==m)
    {
        cout<<'1';
        if(n1[0]==m1[0]&&n1[1]==m1[1])
        {
            cout<<'1';
            if(n1[2]=='A'||n1[2]=='B'||n1[2]=='C')
            {
                if(m1[2]=='A'||m1[2]=='B'||m1[2]=='C')
                {
                    cout<<'1';
                    if(m1[2]-n1[2]==1||n1[2]-m1[2]==1)
                    {
                        cout<<'1';
                        return 0;
                    }
                    else
                    {
                        cout<<'0';
                        return 0;
                    }
                }
            }
            if(n1[2]=='D'||n1[2]=='E')
            {
                if(m1[2]=='D'||m1[2]=='E')
                {
                    cout<<"11";
                    return 0;
                }
            }
            else
            {
                cout<<"00";
                return 0;
            }
        }
        else
        {
            cout<<"000";
            return 0;
        }
    }
    else
        cout<<"0000";
    return 0;
}
