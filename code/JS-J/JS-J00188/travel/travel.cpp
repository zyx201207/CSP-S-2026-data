#include<bits/stdc++.h>
using namespace std;
long long a,b,c,d,e,f,g,h,l,k;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    for(char x:c1)
    {
        b=c1.size();
        a+=pow(10,b-1)*(x-'0');
        b--;
    }
    for(char y:c2)
    {
        d=c2.size();
        c+=pow(10,d-1)*(y-'0');
        d--;
    }
    for(char x:s1)
    {
        if(x>='0'&&x<='9')
        {
            e=s1.size()-1;
            f+=pow(10,e-1)*(x-'0');
            e--;
        }
        else
        {
            char i=x;
            l=x-'0';
        }
    }
    for(char y:s2)
    {
        if(y>='0'&&y<='9')
        {
            g=s2.size()-1;
            h+=pow(10,g-1)*(y-'0');
            g--;
        }
        else
        {
            char j=y;
            k=y-'0';
        }
    }
    if(a==c)
    {
        printf("%d",1);
        if(f==h)
        {
            printf("%d",1);
            if(k<=19&&l<=19||(k>=20&&l>=20))
            {
                printf("%d",1);
                if(abs(k-l)==1)
                    printf("%d",1);
                else
                    printf("%d",0);
            }

            else
                printf("%d%d",0,0);
        }
        else
        printf("%d%d%d",0,0,0);
    }
    else
        printf("%d%d%d%d",0,0,0,0);
    return 0;
}
