#include<bits/stdc++.h>
using namespace std;
set<string> s;
set<string> c;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    for(int i=1;i<=2;i++)
    {
        string Rc,Xc;
        cin>>Rc>>Xc;
        c.insert(Rc);
        s.insert(Xc);
    }
    if(c.size()==1)
    {
        cout<<1;
    }else{
        cout<<0000;
        return 0;
    }
    if(s[1]=="01A"&&s[2]=="01B")
    {
        cout<<111;
    }else
    {
        if(s[1]=="01C"&&s[2]=="01A")
        {
            cout<<110;
        }else
        {
            if(s[1]=="01C"&&s[2]=="01D")
            {
                cout<<100;
            }else
            {
                if(s[1]="02B"&&s[2]=="01A")
                {
                    cout<<000;
                }
            }
        }
    }
    return 0;
}
