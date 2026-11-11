#include <bits/stdc++.h>
#define ll long long
using namespace std;
string c1,s1,c2,s2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    bool flag1 = c1==c2;
    bool flag2 = s1[0]==s2[0]&&s1[1]==s2[1]&&flag1;
    bool flag3 = ((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D'))&&flag2;
    bool flag4 = (abs(s1[2]-s2[2])<=1)&&flag3;
    cout << flag1 << flag2 << flag3 << flag4;
    return 0;
}
