#include<iostream>
#include<cstdio>
using namespace std;

string ans;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    string c,s,d,f;
    cin>>c>>s>>d>>f;
    if(c==d)
    {
        ans[0]='1';
        if((s[0]==f[0])&&(s[1]==f[1]))
        {
            ans[1]='1';
            if(s[2]<='C'&&f[2]<='C')
            {
                ans[2]='1';
                if(abs(int(s[2])-int(f[2]))==1)
                {
                    cout<<"1111";
                }
                else
                {
                    cout<<"1110";
                }
            }
            else if(s[2]>'C'&&f[2]>'C')
            {
                cout<<"1111";
            }
            else
            {
                cout<<"1100";
            }
        }
        else
        {
            cout<<"1000";
        }
    }
    else
    {
        cout<<"0000";
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}
