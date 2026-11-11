#include<bits/stdc++.h>
using namespace std;
char c1[3],s1[4],c2[3],s2[4];
bool a1=0,a2=0,a3=0,a4=0;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    for(int i=1;i<=2;i++) cin >> c1[i];
    for(int i=1;i<=3;i++) cin >> s1[i];
    for(int i=1;i<=2;i++) cin >> c2[i];
    for(int i=1;i<=3;i++) cin >> s2[i];
    if(c1[1]==c2[1] && c1[2]==c2[2])
    {
        a1=1;
        if(s1[1]==s2[1] && s1[2]==s2[2])
        {
            a2=1;
            if((s1[3]=='A' && s2[3]=='C') || (s1[3]=='C' && s2[3]=='A'))
            {
                a3=1;
                a4=0;
            }
            if((s1[3]=='A' && s2[3]=='B') || (s1[3]=='B' && s2[3]=='A') || (s1[3]=='B' && s2[3]=='C') || (s1[3]=='C' && s2[3]=='B') || (s1[3]=='D' && s2[3]=='F') || (s1[3]=='F' && s2[3]=='D'))
            {
                a3=1;
                a4=1;
            }
        }
    }
    cout << a1 << a2 << a3 << a4;
    return 0;
}
