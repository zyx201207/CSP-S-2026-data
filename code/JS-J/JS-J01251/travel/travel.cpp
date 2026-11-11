#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s1,s2,s3,s4;
    cin>>s1>>s2>>s3>>s4;
    string s = "";
    if(s1 == s3)
    {
        s = s+"1";
        if(s2[0] == s4[0] && s2[1] == s4[1])
        {
            s = s+"1";
            if(s2[2] <= 'C' && s2[2] >= 'A')
            {
                if(s4[2] <= 'C' && s4[2] >= 'A')
                {
                    s = s+"1";
                    if(s2[2] == 'B' || s4[2] == 'B')
                    {
                        s = s+"1";
                    }
                    else
                    {
                        s = s+"0";
                    }
                }
                else
                {
                    s = s+"00";
                }
            }
            else
            {
                if(s2[2] <= 'F' && s2[2] >= 'D')
                {
                    s = s+"11";
                }
                else
                {
                    s = s+"00";
                }
            }
        }
        else
        {
            s = s+"000";
        }
    }
    else
    {
        s = s+"0000";
    }
    cout<<s<<'\n';
    return 0;
}
