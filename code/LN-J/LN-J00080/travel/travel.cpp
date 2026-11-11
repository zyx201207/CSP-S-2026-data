#include<climits>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
bool pdd(char a,char b)
{
    if(a=='A'&&b=='B')
        return 1;
    if(b=='A'&&a=='B')
        return 1;
    if(a=='B'&&b=='C')
        return 1;
    if(b=='B'&&a=='C')
        return 1;
    if(a=='E'&&b=='F')
        return 1;
    if(b=='E'&&a=='F')
        return 1;
    return 0;
}
signed int main()
{
    signed long long int L(0),n(0),J(0),z(0),j(8),l(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    std::string c1,s1,c2,s2;
    std::cin>>c1>>s1>>c2>>s2;
    if(c1==c2)
    {
        putchar('1');
        if(s1[0]==s2[0]&&s1[1]==s2[1])
        {
            putchar('1');
            if(std::max(s1[2],s2[2])<='C'||std::min(s1[2],s2[2])>='E')
            {
                putchar('1');
                if(pdd(s1[2],s2[2]))
                    putchar('1');
                else
                    putchar('0');
            }
            else
                puts("00");
        }
        else
            puts("000");
    }
    else
        puts("0000");
    return 0;
}
