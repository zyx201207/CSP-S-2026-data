#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a1,a2,b1,b2;
    cin>>a1>>a2>>b1>>b2;
    if(a1==b1)
    {
        cout<<1;
        if(a2[0]==b2[0]&&a2[1]==b2[1])
        {
            cout<<1;
            char a=a2[2],b=b2[2];
            if(a>b)
            {
                swap(a,b);
            }
            if(a<'D'&&b<'D')
            {
                cout<<1;
                if(b-a==1)
                {
                    cout<<1;
                }
                else
                {
                    cout<<0;
                }
            }
            else if(a>'C'&&b>'C')
            {
                cout<<11;
            }
            else
            {
                cout<<"00";
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
    fclose(stdin);
    fclose(stdout);
    return 0;
}
