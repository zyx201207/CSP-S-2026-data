#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int a[4] = {0};
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 == c2)
    {
        a[0] = 1;
        string s1r = s1.substr(0,2);
        string s2r = s2.substr(0,2);
        if(s1r == s2r)
        {
            a[1] = 1;
            string s1c = s1.substr(2);
            string s2c = s2.substr(2);
            if((s1c >= "A" && s1c <= "C") && (s2c >= "A" && s2c <= "C"))
            {
                a[2] = 1;
                if(s1c == "A" && s2c == "B" || s1c == "B" && s2c == "A" || s1c == "B" && s2c  == "C" || s1c == "C" && s2c == "B") a[3] = 1;
            }else if(s1c >= "D" && s1c <= "E" && s2c >= "D" && s2c <= "E")
            {
                a[2] = 1;
                if(s1c == "D" && s2c == "E" || s1c == "E" && s2c == "D") a[3] = 1;
            }
        }
    }
    for(int  i = 0 ; i < 4 ; i++) cout << a[i];
    return 0;
}

