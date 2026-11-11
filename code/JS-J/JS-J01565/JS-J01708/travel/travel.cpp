#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[10];
int b[10];
bool p[10]={1,1,1,1,1};
signed main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2;
    string s1,s2;
    cin >> c1 >> s1 >> c2 >> s2;
    a[1]=(s1[0]-'0')*10+(s1[1]-'0');
    b[1]=(s2[0]-'0')*10+(s2[1]-'0');
    a[2]=s1[2]-'A'+1;
    b[2]=s2[2]-'A'+1;
    //cout << a[1] << " " << a[2] << " " << b[1] << " " << b[2] << endl;
    if(a[2]==6)
    {
        a[2]--;
    }
    if(b[2]==6)
    {
        b[2]--;
    }
    if(c1!=c2)
    {
        p[1]=0;
        p[2]=0;
        p[3]=0;
        p[4]=0;
    }
    else
    {
        if(a[1]!=b[1])
        {
            p[2]=0;
            p[3]=0;
            p[4]=0;
        }
        else
        {
            if(a[2]>=4 && b[2]<=3 || a[2]<=3 && b[2]>=4)
            {
                p[3]=0;
                p[4]=0;
            }
            else
            {
                if(abs(a[2]-b[2])>1)
                {
                    p[4]=0;
                }
            }
        }
    }
    for(int i=1;i<=4;i++)
    {
        cout << p[i];
    }
    return 0;
}