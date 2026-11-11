#include <bits/stdc++.h>
using namespace std;
int a[7];
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2,s1,s2;
    char a1,a2;
    string ans="";
    cin >> c1 >> s1 >> a1 >> c2 >> s2 >> a2;
    int x = a1-'A'+1;
    int y = a2-'A'+1;
    for(int i=1;i<=4;i++)
        a[i] = 0;
    if(c1 == c2)
    {
        ans+='1';
        if(s1 == s2)
        {
            ans+='1';
            if((x <= 3 && y<=3) || (x > 3 && y > 3))
            {
                ans+='1';
                if(abs(x-y) == 1) ans+='1';
                else ans+='0';
            }
            else ans+="00";
        }
        else ans+="000";
    }
    else ans+="0000";
    cout << ans;
    return 0;
}
