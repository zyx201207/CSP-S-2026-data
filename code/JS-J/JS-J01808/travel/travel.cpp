#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2;
    string s1,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)
    {
        cout<<'1';
        if(s1[0]==s2[0]&&s1[1]==s2[1])
        {
            cout<<'1';
            if(s1[2]<='C'&&s2[2]<='C'||s1[2]>='D'&&s2[2]>='D')
            {
                cout<<'1';
                int a,b;
                a=s1[2]-'A'+1;
                b=s2[2]-'A'+1;
                if(s1[2]=='F')a--;
                if(s2[2]=='F')b--;
                if(abs(a-b)==1)cout<<'1';
                else cout<<'0';
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
    return 0;
}
