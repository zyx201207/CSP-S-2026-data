#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a1,a2,b1,b2;
    string s1,s2;
    cin>>a1>>b1>>s1>>a2>>b2>>s2;
    if(a1!=a2)
    {
        cout<<"0000";
    }
    else
    {
        cout<<"1";
        if(b1!=b2)
        {
            cout<<"000";
        }
        else
        {
            cout<<1;
            if((s1=="A"||s1=="B"||s1=="C")&&(s2=="A"||s2=="B"||s2=="C"))
            {
                
				cout<<"1";
                if((s1=="A"&&s2=="C")||(s2=="A"&&s1=="C"))
                {
                    cout<<"0";
                }
                else
                {
                    cout<<"1";
                }
            }
            else if((s1=="D"||s1=="F")&&(s2=="D"||s2=="F"))
            {
                cout<<"11";
            }
            else
            {
                cout<<"00";
                exit(0);
            }
        }
    }
    return 0;
}
