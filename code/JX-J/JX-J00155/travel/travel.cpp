#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("traveL.out","w",stdout);
    string a;
    long long i;
   getline(cin,a);
    if(a[0]==a[7]&&a[1]==a[8])
    {
        cout<<1;
        if(a[3]==a[10]&&a[4]==a[11])
        {
            cout<<1;

            if(a[5]==a[12]-1||a[5]==a[12]+1)
            {

                if(a[5]=='D'&&a[12]=='D')
                     {
                         if(a[5]!='C'&&a[12]!='C')
                         cout<<"11";
                         else
                        cout<<"00";
                     }
                else
                cout<<"00";
            }
            else if(a[5]==a[12]-2||a[12]==a[5]-2)
            {

                if(a[5]=='F'||a[12]=='F')
                {
                    cout<<"00";
                }
                else if(a[5]=='D'||a[12]=='D')
                    cout<<"00";
                else
                cout<<"10";
            }

            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
    return 0;
}
