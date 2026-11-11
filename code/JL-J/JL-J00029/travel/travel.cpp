#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s1,s2,c1,c2,ans;
    int a,b;
    char aa,bb;
    cin >> c1 >> s1 >> c2 >> s2;
    if (c1 == c2)
    {
        ans[0] = 1;
    }
    else
    {
        cout << "0000";
        return 0;
    }
    a = s1[0] * 10 + s1[1];
    b = s2[0] * 10 + s2[1];
    if (a == b)
    {
        ans[1] = 1;
    }
    else
    {
        cout << "1000";
        return 0;
    }
    aa = s1[2];
    bb = s2[2];
    if (aa == 'A' && bb == 'B' || aa == 'A' && bb == 'C' || aa == 'B' && bb == 'A' || aa == 'B' && bb == 'C' || aa == 'C' && bb == 'A' || aa == 'C' && bb == 'B')
    {
        ans[2] = 1;
    }
    else if (aa == 'D' && bb == 'F' || aa == 'F' && bb == 'D')
    {
        ans[2] = 1;
    }
    else
    {
        cout << "1100";
        return 0;
    }
    if (aa == 'A' && bb == 'B' || aa == 'B' && bb == 'A' || aa == 'B' && bb == 'C' || aa == 'C' && bb == 'B' || aa == 'D' && bb == 'F' || aa == 'F' && bb == 'D')
    {
        ans[3] = 1;
        cout << "1111";
    }
    else
    {
        cout << "1110";
    }
    return 0;
}
