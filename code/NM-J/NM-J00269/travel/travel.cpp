#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2,s1,s2;
    cin>>c1>>s1>>c2>>s2;
    string sf,ss;
    sf=s1[0]+s1[1];
    ss=s2[0]+s2[1];
    char sfl=s1[2];
    char ssl=s2[2];
    if(c1==c2)
    {
        cout<<1;
        if(sf==ss)
        {
            cout<<1;
            if(sfl>='A' && sfl<='C' && ssl>='A' && ssl<='C')
            {
                cout<<1;
                if(sfl+1==ssl || sfl-1 == ssl)
                {
                    cout<<1;
                }
                else
                {
                    cout<<0;
                }
            }
            else if(sfl>='D' && sfl<='F' && ssl>='D' && ssl<='F')
            {
                cout<<1;
                if(sfl+1==ssl || sfl-1 == ssl)
                {
                    cout<<1;
                }
                else
                {
                	cout<<0;
				}
            }
            else
            {
                cout<<0<<0;
            }
        }
        else
        {
            cout<<0<<0<<0;
        }
    }
    else
    {
        cout<<0<<0<<0<<0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
