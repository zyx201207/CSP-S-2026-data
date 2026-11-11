#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string ax,bx;
    string aa,bb;
    cin>>ax>>aa>>bx>>bb;
    int a=(ax[0]-'0')*10+(ax[1]-'0');
    int b=(bx[0]-'0')*10+(bx[1]-'0');
    int an,bn;
    int x=aa[0]-'0';
    int xx=aa[1]-'0';
    an=(x*10+xx);
    int v=bb[0]-'0';
    int yy=bb[1]-'0';
    bn=(v*10+yy);
    char ap,bp;
    ap=aa[2];
    bp=bb[2];
    if(a==b)
    {
        cout << 1;
    }
    else
    {
        cout << 0;
    }
    if(an==bn&&a==b)
    {
        cout << 1;
    }
    else
    {
        cout << 0;
    }
    if(a==b)
    {
        if(an==bn)
        {
            if((ap=='F'||ap=='D')&&(bp=='F'||bp=='D'))
            {
                cout << 1;
            }
            else if((ap=='A'||ap=='B'||ap=='C')&&(bp=='A'||bp=='B'||bp=='C'))
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
    else
    {
        cout << 0;
    }
    if(a==b)
    {
        if(((an==(bn+1))||(an==(bn-1)))&&ap==bp)
        {
            cout << 1;
        }
        else if(((ap=='D'&&bp=='F')||(ap=='F'&&bp=='D'))&&an==bn)
        {
            cout << 1;
        }
        else if(((ap=='A'&&bp=='B')||(ap=='B'&&bp=='A'))&&an==bn)
        {
            cout << 1;
        }
        else if(((ap=='B'&&bp=='C')||(ap=='C'&&bp=='B'))&&an==bn)
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

    return 0;
}
