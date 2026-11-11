#include<bits/stdc++.h>
using namespace std;
char r[4],x[4];
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);   
    cin>>r[4]>>x[4];
    if(r[0]!=x[0]||r[1]!=x[1])
    {
        cout<<"0000";
        return 0;
    }
    else
    {
        cout<<1;
        if(r[2]!=x[2]||x[3]!=r[3])
        {
            cout<<"000";
            return 0;
        }
        else
        {
            cout<<1;
            if((r[4]=='A'||'B'||'C'&&x[4]=='D'||'E')||(x[4]=='A'||'B'||'C'&&r[4]=='D'||'E'))
            {
                cout<<"00";
                return 0;
            }
            else
            {
                if(r[4]=='A'&&x[4]=='B'||r[4]=='B'&&x[4]=='A')
                {
                    cout<<1;
                    return 0;
                }
                if(r[4]=='C'&&x[4]=='B'||r[4]=='B'&&x[4]=='C')
                {
                    cout<<1;
                    return 0;
                }
                if(r[4]=='D'&&x[4]=='E'||r[4]=='E'&&x[4]=='D')
                {
                    cout<<1;
                    return 0;
                }
                cout<<0;
            }
        }
    }
    return 0;
}