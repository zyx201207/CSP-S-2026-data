#include <bits/stdc++.h>
using namespace std;
char sa[3];
char sb[3];
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    long long a,b;
    string a1[3],b1[3];
    cin>>a;
    cin>>sa[1];
    cin>>sa[2];
    cin>>sa[3];
    cin>>b;
    cin>>sb[1];
    cin>>sb[2];
    cin>>sb[3];
    if(a == b)
    {
        cout<<"1";
    }
    if(a != b)
    {
        cout<<"0000";
        return 0;
    }
    if(sa[1] == sb[1])
    {
        if(sa[2] == sb[2])
        {
            cout<<"1";
            if(sa[3] - sb[3] == 1 || sb[3] - sa[3] == 1 && sa[3]-'A'<=3 && sb[3]-'A'<=3)
            {
                cout<<"11";
                return 0;
            }
            else if(sa[3] - sb[3] != 1 || sb[3] - sa[3] != 1 && sa[3]-'A'<=3 && sb[3]-'A'<=3)
            {
                cout<<"00";
                return 0;
            }
            if(sa[3] - sb[3] == 2 || sa[3] - sb[3] == 2 && sa[3]-'A'>3 && sb[3]-'A'>3)
            {
                cout<<"11";
                return 0;
            }
            else
            {
                cout<<"00";
            }
        }
        else
        {
            cout<<"000";
            return 0;
        }
    }
    else
    {
        cout<<"000";
        return 0;
    }
    return 0;
}
