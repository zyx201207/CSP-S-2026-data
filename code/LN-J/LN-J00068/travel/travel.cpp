#include <bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int x;
char c;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s1>>s2>>s3>>s4;
    if(s1!=s3)
    {
        cout<<"0000";
        return 0;
    }
    else
    {
        cout<<"1";
        int hang1=(s2[0]-'0')*10+s2[1]-'0',hang2=(s4[0]-'0')*10+s4[1]-'0';
        if(hang1!=hang2)
        {
            cout<<"000";
            return 0;
        }
        else
        {
            cout<<"1";
            int lier=s2[2]-'A',liex=s4[2]-'A';
            int lie1=(s2[2]-'A'<3 ? 1 : 2),lie2={s4[2]-'A'<3 ? 1 : 2};
            if(lie1!=lie2)
            {
                cout<<"00";
                return 0;
            }
            else
            {
                cout<<"1";
                if(lie1==1)
                {
                    if(abs(lier-liex)==1)
                    {
                        cout<<"1";
                        return 0;
                    }
                    else
                    {
                        cout<<"0";
                        return 0;
                    }
                }
                else
                {
                    cout<<"1";
                    return 0;
                }
            }
        }
    }
}
