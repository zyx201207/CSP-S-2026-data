#include<bits/stdc++.h>
using namespace std;
struct che
{
    int xiang;
    string s;
}a[27];
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a[1].xiang>>a[1].s;
    cin>>a[2].xiang>>a[2].s;

    if(a[1].xiang==a[2].xiang)
    {
        cout<<1;
        string s1=a[1].s.substr(0,2);
        string s2=a[2].s.substr(0,2);


        if(s1==s2)
        {
            cout<<1;
            char s11=a[1].s[2];
            char s22=a[2].s[2];


            if(s11>='A'&&s11<='C'&&s22>='A'&&s22<='C')
            {
                cout<<1;
                if(abs(s11-s22)==1)
                {
                    cout<<1;
                }
                else
                {
                    cout<<0;
                }
            }
            else if(s11>='D'&&s11<'E'&&s22>='D'&&s22<'E')
            {
                cout<<1;

            }
            else{
                cout<<0<<0;
            }


        }
        else{
            cout<<0<<0<<0;
        }


    }
    else
    {
        cout<<0<<0<<0<<0;
    }


    return 0;
}
