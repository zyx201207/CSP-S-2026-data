#include<cstdio>
#include <iostream>
using namespace std;
int main()
{
        freopen("travel.in","r",stdin);
        freopen("travel.out","w",stdout);
        string c1,c2,s1,s2;
        cin>>c1>>s1>>c2>>s2;
        if(c1==c2 && s1!=s2)
        {
                cout<<"1 1 1 1";
        }
        else if(c1!=c2 && c2==s2)
        {
                cout<<" 0 1 1 1";
        }
        else if(c1==s1 && c2!=s2)
        {
                cout<<"1 1 0 0";
        }
        else if(c1!=s1 && c2!=s2)
                cout<<"1 0 0 0";
        else
            cout<<"0 0 0 0";
        return 0;
}
