#include <bits/stdc++.h>
using namespace std;
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
int main()
{
    int ci,cj;
    char si,sj;
    cin>>ci;
    cin>>si;
    cin>>cj;
    cin>>sj;
    sj-=1;
    cout<<si<<" "<<sj<<endl;
    cout<<ci<<" "<<cj<<endl;
    if(ci%cj==0)
    {
        cout<<"1";
        if(si==sj || si==sj+2)
        {
            cout<<"1";
            if(ci==cj)
            {
                cout<<"1";
                if(ci==cj)
                {
                    cout<<"1";
                }
                else
                {
                    cout<<"0";
                }
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
	return 0;
}
