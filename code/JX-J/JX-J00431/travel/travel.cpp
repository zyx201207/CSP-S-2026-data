#include <iostream>
using namespace std;
string a,b,c,d;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    if(a==c)
    {
        cout<<1;
        if(b[0]==d[0] and b[1]==d[1])
        {
            cout<<1;
            if (b[2]-'A'<=2 and b[2]-'A'>=-2 and d[2]-'A'<=2 and d[2]-'A'>=-2)
            {
                cout<<1;
                if(b[2]-d[2]==1 or b[2]-d[2]==-1)
                {
                    cout<<1;
                }
                else
                {
                    cout<<0;
                }
            }
            else if(b[2]-'D'<=3 and b[2]-'D'>=0 and d[2]-'D'<=3 and d[2]-'D'>=0)
            {
                cout<<1;
                if(b[2]-d[2]==1 or b[2]-d[2]==-1)
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
                cout<<00;
            }
        }
        else
        {
            cout<<000;
        }
    }
    else
    {
        cout<<0000;
    }
}
