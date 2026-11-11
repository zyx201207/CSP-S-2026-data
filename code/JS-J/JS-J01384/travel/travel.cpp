#include <bits/stdc++.h>
using namespace std;
int to(char a)
{
    if (a == 'A') return 1;
    if (a == 'B') return 2;
    if (a == 'C') return 3;
    if (a == 'D') return 4;
    if (a == 'F') return 5;
}
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    int t1 = 0,t2 = 0,t3 = 0,t4 = 0;
    for (int i=0;i<2;i++)
    {
        if (c1[i] != '0' || i == 1) t1 = t1*10 + c1[i] - '0';
        if (c2[i] != '0' || i == 1) t2 = t2*10 + c2[i] - '0';
    }
    for (int i=0;i<2;i++)
    {
        if (s1[i] != '0' || i == 1) t3 = t3*10 + s1[i] - '0';
        if (s2[i] != '0' || i == 1) t4 = t4*10 + s2[i] - '0';
    }
    char a1 = s1[2],b1 = s2[2];
    int a = to(a1),b = to(b1);
    if (t1 == t2)
    {
        cout<<"1";
        if (t3 == t4)
        {
            cout<<"1";
            if ((a <= 3 && b <= 3) || (a > 3 && b > 3))
            {
                cout<<"1";
                if (abs(a-b) <= 1)
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
    cout<<"\n";
    return 0;
}
