#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    string s1,s2;
    cin>>n>>s1>>m>>s2;
    if(n==m)
    {
        string a1=s1.substr(0,2),a2=s2.substr(0,2);
        if(a1==a2)
        {
            if(((s1[2]=='A' || s1[2]=='B' || s1[2]=='C') && (s2[2]=='A' || s2[2]=='B' || s2[2]=='C')) || ((s1[2]=='D' || s1[2]=='E') && (s2[2]=='D' || s2[2]=='E')))
            {
                int c=abs(s1[2]-s2[2]);
                if(c==1)
                {
                    cout<<"1111";
                }
                else
                {
                    cout<<"1110";
                }
            }
            else
            {
                cout<<"1100";
            }
        }
        else
        {
            cout<<"1000";
        }
    }
    else
    {
        cout<<"0000";
    }
    cout<<'\n';
    return 0;
}
