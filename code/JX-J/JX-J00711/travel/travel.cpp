#include<bits/stdc++.h>
using namespace std;
char c1[5],s1[5],c2[5],s2[5],ans[5]={'0','0','0','0'};
int l1,l2,f1=0,f2=0,f3=0;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(s1[2]=='A' || s1[2]=='B' || s1[2]=='C')
        l1=1;
    else l1=2;
    if(s2[2]=='A' || s2[2]=='B' || s2[2]=='C')
        l2=1;
    else l2=2;
    if(c1[0]==c2[0] && c1[1]==c2[1])
    {
        ans[0]='1';
        if((s1[0]==s2[0] && s1[1]==s2[1]))
        {
            ans[1]='1';
            if(l1==l2 )
            {
                ans[2]='1';
                if(abs(s1[2]-s2[2])==1)
                {
                    ans[3]='1';
                }
            }
        }
    }
    for(int i=0;i<=3;i++)
    {
        cout<<ans[i];
    }
    return 0;
}
