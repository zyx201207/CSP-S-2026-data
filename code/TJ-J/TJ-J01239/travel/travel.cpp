#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int l1,l2;
    string h1,h2;
    cin >> l1 >> h1 >>l2 >> h2;
    int z1=h1[0]*10+h1[1];
    int z2=h2[0]*10+h2[1];
    int a1,a2;
    if(h1[2]=='A')
    {
        a1=1;
    }
    else if(h1[2]=='B')
    {
        a1=2;
    }
    else if(h1[2]=='C')
    {
        a1=3;
    }
    else if(h1[2]=='D')
    {
        a1=4;
    }
    else if(h1[2]=='F')
    {
        a1=5;
    }
    if(h2[2]=='A')
    {
        a2=1;
    }
    else if(h2[2]=='B')
    {
        a2=2;
    }
    else if(h2[2]=='C')
    {
        a2=3;
    }
    else if(h2[2]=='D')
    {
        a2=4;
    }
    else if(h2[2]=='F')
    {
        a2=5;
    }
    if(l1==l2)
    {
        cout << 1;
    }
    else
    {
        cout << "0000";
        return 0;
    }
    if(z1==z2)
    {
        cout << 1;
    }
    else
    {
        cout << "000";
        return 0;
    }
    if(a1>=4&&a2>=4)
    {
        cout << 1;
    }
    else if(a1<=3&&a2<=3)
    {
        cout << 1;
    }
    else
    {
        cout << 0;
    }
    int xl = abs(a1-a2);

    if(a1!=3&&a2!=4)
    {
        if(a1!=4&&a2!=3)
        {
            if(xl==1)
            {
                cout << 1;
            }
            else
            {
                cout << 0;
            }
        }
        else
        {
            cout << 0;
        }
    }
    else{
        cout << 0;
    }
    return 0;
}
