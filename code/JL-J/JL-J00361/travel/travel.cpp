#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1[5],s2[5],a,b,c,d,e,f;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1[5]>>c2>>s2[5];
    a=s1[1];
    b=s1[2];
    c=s1[3];
    d=s2[1];
    e=s2[2];
    f=s2[3];
    if(c1==c2)
    {
        cout<<"1"<<" ";
        if(a==d||b==e)
        {
            cout<<"1"<<" ";
            if(c=="A")
            {
                if(f=="C")
                {
                    cout<<"1"<<" "<<"0";
                }
                if(f=="B")
                {
                    cout<<"1"<<" "<<"1";
                }
                else
                {
                    cout<<"0"<<" "<<"0";
                }
            }
            if(c=="B")
            {
                if(f=="A"&&f=="C")
                {
                    cout<<"1"<<" "<<"1";
                }
                else
                {
                    cout<<"0"<<" "<<"0";
                }
            }
            if(c=="C")
            {
                if(f=="A")
                {
                    cout<<"1"<<" "<<"0";
                }
                if(f=="B")
                {
                    cout<<"1"<<" "<<"1";
                }
                else
                {
                    cout<<"0"<<" "<<"0";
                }
            }
            if(c=="D")
            {
                if(f=="F")
                {
                    cout<<"1"<<" "<<"1";
                }
                else
                {
                    cout<<"0"<<" "<<"0";
                }
            }
            if(c=="F")
            {
                if(f=="D")
                {
                    cout<<"1"<<" "<<"1";
                }
                else
                {
                    cout<<"0"<<" "<<"0";
                }
            }
        }
        else
        {
            cout<<"0"<<" "<<"0"<<" "<<"0";
            return 0;
        }
    }
    else
    {
        cout<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"0";
        return 0;
    }
    return 0;
}
