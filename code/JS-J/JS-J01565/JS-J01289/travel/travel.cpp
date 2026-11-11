#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s1,s2,c1,c2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)
    {
        cout<<'1';
        string ts1=s1.substr(0,2);
        string ts2=s2.substr(0,2);
        if(ts1==ts2)
        {
            cout<<'1';
            if(s1[2]<='C'&&s2[2]<='C'||s1[2]>'C'&&s2[2]>'C')
            {
                cout<<'1';
                if(abs(s1[2]-s2[2])==1)
                {
                    if(s1[2]=='C'&&s2[2]=='D'||s2[2]=='C'&&s1[2]=='D')
                    {

                        cout<<'0';
                    }
                    else cout<<'1';
                }
                else if(s1[2]=='D'&&s2[2]=='F'||s1[2]=='F'&&s2[2]=='D')
                    cout<<'1';
                else cout<<'0';
            }
            else cout<<"00";

        }
        else cout<<"000";
    }
    else cout<<"0000";


    return 0;
}
