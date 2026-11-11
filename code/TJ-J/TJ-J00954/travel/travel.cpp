#include <bits/stdc++.h>
using namespace std;
string c1,c2,d1,d2;
int c,s;
string ans="";
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> c1>>c2>>d1>>d2;
    if(c1!=d1)
    {
        ans="0000";
    }
    else
    {
        ans+='1';
        if(c2[0]!=d2[0]||c2[1]!=d2[1])
        {
            ans+="000";
        }
        else
        {
            ans+='1';
            if(c2[2]<='C'&&d2[2]<='C'||c2[2]>='D'&&d2[2]>='D')
            {
                ans+='1';
                if(c2[2]=='B'||d2[2]=='B'||c2[2]=='D'&&d2[2]=='F'||c2[2]=='F'&&d2[2]=='D')
                {
                    ans+='1';
                }
                else
                {
                    ans+='0';
                }
            }
            else
            {
                ans+="00";
            }
        }
    }
    cout << ans;
    return 0;
}
