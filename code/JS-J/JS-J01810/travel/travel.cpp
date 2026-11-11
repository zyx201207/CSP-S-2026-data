#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    bool flag1 = (c1==c2);
    cout<<(flag1?'1':'0');
    bool flag2 = flag1;
    for(int i = 0;i < 2;i++)
    {
        if(s1[i]!=s2[i])
        {
            flag2 = false;
        }
    }
    cout<<(flag2?'1':'0');
    bool flag3 = flag2 && ((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D'));
    cout<<(flag3?'1':'0');
    bool flag4 = flag3 && (abs((int)(s1[2]-s2[2])) == 1);
    cout<<(flag4?'1':'0');
    return 0;
}
