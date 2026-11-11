#include <bits/stdc++.h>
using namespace std;
struct seat
{
    int x;//chexiang
    int y;//pai
    int z;//zuowei 1-5
}s1,s2;
string c,s;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> c >> s;
    s1.x=(c[0]-'0')*10+c[1];
    s1.y=(s[0]-'0')*10+s[1];
    s1.z=s[2]-'A';
    cin >> c >> s;
    s2.x=(c[0]-'0')*10+c[1];
    s2.y=(s[0]-'0')*10+s[1];
    s2.z=s[2]-'A';
    if(s2.z==5)s2.z=4;
    if(s1.z==5)s1.z=4;
    if(s1.x==s2.x)
    {
        cout << 1;
        if(s1.y==s2.y)
        {
            cout << 1;
            if((s1.z<=2 && s2.z<=2)||(s1.z>2 && s2.z>2))
            {
                cout << 1;
                if(abs(s1.z-s2.z)==1)cout << 1;
                else cout << 0;
            }
            else cout << "00";
        }
        else cout << "000";
    }
    else cout << "0000";
    return 0;
}
