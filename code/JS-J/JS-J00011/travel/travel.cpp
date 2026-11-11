#include<bits/stdc++.h>
using namespace std;
int m1,n1,m2,n2;
char c1,c2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    scanf("%d%d%c%d%d%c",&m1,&n1,&c1,&m2,&n2,&c2);
    if(m1 == m2)
    {
        printf("%d",1);
        if(n1 == n2)
        {
            printf("%d",1);
            if(c1 == 'A')
            {
                if(c2 == 'B')
                {
                    printf("%d",1);
                    printf("%d",1);
                }
                else if(c2 == 'C')
                {
                    printf("%d",1);
                    printf("%d",0);
                }
                else
                {
                    printf("%d",0);
                    printf("%d",0);
                }
            }
            else if(c1 == 'B')
            {
                if(c2 == 'A' || c2 == 'C')
                {
                    printf("%d",1);
                    printf("%d",1);
                }
                else
                {
                    printf("%d",0);
                    printf("%d",0);
                }
            }
            else if(c1 == 'C')
            {
                if(c2 == 'B')
                {
                    printf("%d",1);
                    printf("%d",1);
                }
                else if(c2 == 'A')
                {
                    printf("%d",1);
                    printf("%d",0);
                }
                else
                {
                    printf("%d",0);
                    printf("%d",0);
                }
            }
            else if(c1 == 'D')
            {
                if(c2 == 'F')
                {
                    printf("%d",1);
                    printf("%d",1);
                }
                else
                {
                    printf("%d",0);
                    printf("%d",0);
                }
            }
            else if(c1 == 'F')
            {
                if(c2 == 'D')
                {
                    printf("%d",1);
                    printf("%d",1);
                }
                else
                {
                    printf("%d",0);
                    printf("%d",0);
                }
            }
        }
        else printf("%d",0);
    }
    else printf("%d",0);
    return 0;
}
