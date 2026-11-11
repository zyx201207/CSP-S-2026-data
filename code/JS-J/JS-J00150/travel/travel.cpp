#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    char c1[2],s1[3];
    scanf("%s%s",&c1,&s1);
    string s=s1;
    char c2[2],s2[3];
    scanf("%s%s",&c2,&s2);
    if(c1[0]!=c2[0]||c1[1]!=c2[1])
    {
        printf("%s","0000");
    }
    else {
        printf("%c",'1');
        if(s[0]==s2[0]&&s[1]==s2[1])
        {
            printf("%c",'1');
            if(s[2]-'A'+s2[2]-'A'==8)
            {
                printf("%s","11");
            }
            else if(s[2]-'A'<3&&s2[2]-'A'<3)
            {
                printf("%c",'1');
                if(s[2]-s2[2]==1||s[2]-s2[2]==-1)
                {
                    printf("%c",'1');
                }
                else printf("%c",'0');
            }
            else {
                printf("%s","00");
            }
        }
        else {
            printf("%s","000");
        }
    }
    return 0;
}
