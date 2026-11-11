#include<bits/stdc++.h>
using namespace std;
#define int long long
string c1,c2,s1,s2;
int q[4];
signed main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)
    {
        q[0]=true;
        if(s1[0]==s2[0]&&s1[1]==s2[1])
        {
            q[1]++;
            if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>'C'&&s2[2]>'C'))
            {
                q[2]++;
                if(abs(s1[2]-s2[2])==1)
                {
                    q[3]++;
                }
            }
        }
    }
    for(int i=0;i<=3;i++)
    {
        cout<<q[i];
    }
    return 0;
}
