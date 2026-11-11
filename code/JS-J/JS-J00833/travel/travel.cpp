#include <bits/stdc++.h>
using namespace std;

const int N=5;
char c1[N],s1[N],c2[N],s2[N];
int cnt1,cnt2;
int flag[N];

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>(c1+1)>>(s1+1)>>(c2+1)>>(s2+1);
    if (s1[3]=='A' || s1[3]=='B' || s1[3]=='C')
        cnt1=1;
    else
        cnt1=2;
    if (s2[3]=='A' || s2[3]=='B' || s2[3]=='C')
        cnt2=1;
    else
        cnt2=2;
    char a=s1[3],b=s2[3];
    if (c1[1]==c2[1] && c1[2]==c2[2])
    {
        flag[1]=1;
        if (s1[1]==s1[1] && s1[2]==s2[2])
        {
            flag[2]=1;
            if (cnt1==cnt2)
            {
                flag[3]=1;
                if (a=='A' && b=='B')
                    flag[4]=1;
                if (a=='B')
                {
                    if (b=='A' || b=='C')
                        flag[4]=1;
                }
                if (a=='C' && b=='B')
                    flag[4]=1;
                if (a=='D' && b=='F')
                    flag[4]=1;
                if (a=='F'&& b=='D')
                    flag[4]=1;
            }
        }
    }
    cout<<flag[1]<<flag[2]<<flag[3]<<flag[4];
    return 0;
}
