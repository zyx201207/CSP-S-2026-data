#include<bits/stdc++.h>
using namespace std;
int ca,cb,sa,sb,f;
char a,b;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>ca>>sa>>a;
    cin>>cb>>sb>>b;
    if(ca==cb)
    {
        cout<<1;
        if(sa==sb)
        {
            cout<<1;
            if((a=='A'&&(b=='B'||b=='C'))||(a=='B'&&(b=='A'||b=='C'))||(a=='C'&&(b=='A'||b=='B')))
            {
                cout<<1;
                if(abs(int(b-a))==1)
                    cout<<1;
                else
                    cout<<0;
            }
            else
                f=1;
            if((a=='D'&&b=='F')||(a=='F'&&b=='D'))
            {
                cout<<11;
            }
            else
            {
                if(f==1)
                {
                    cout<<0;
                    cout<<0;
                }
            }
        }
        else
        {
            cout<<0;
            cout<<0;
            cout<<0;
        }
    }
    else
    {
        cout<<0;
        cout<<0;
        cout<<0;
        cout<<0;
    }
    return 0;
}
