#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    int c1,c2,c3,c4;
    char s1,s2;
    cin>>c1>>c2>>s1>>c3>>c4>>s2;
    if(c1==c3)
    {
        cout<<"1";
        if(c2==c4)
        {
            cout<<"1";
            if(s1=='A'&&s2=='B'||s1=='A'&&s2=='C'||s1=='B'&&s2=='A'||s1=='B'&&s2=='C'||s1=='C'&&s2=='B'||s1=='C'&&s2=='A'||s1=='D'&&s2=='F'||s1=='F'&&s2=='D')
            {
                cout<<"1";
                if(s1=='A'&&s2=='B'||s1=='B'&&s2=='A'||s1=='B'&&s2=='C'||s1=='C'&&s2=='B'||s1=='D'&&s2=='F'||s1=='F'&&s2=='D')
                {
                    cout<<"1";
                }
                else cout<<"0";
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
    return 0;
}
