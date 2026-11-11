#include<bits/stdc++.h>
#define int long long
using namespace std;

int c1,c2,s1,s2,a,b,c,d;
char c11,c12,c21,c22,ss11,ss12,ss21,ss22,w1,w2;

signed main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    scanf("%c%c %c%c%c %c%c %c%c%c",
            &c11,&c12,&ss11,&ss12,&w1,&c21,&c22,&ss21,&ss22,&w2);
    c1=(c11-'0')*10+c12-'0',c2=(c21-'0')*10+c22-'0';
    s1=(ss11-'0')*10+ss12-'0',s2=(ss21-'0')*10+ss22-'0';
    // printf("%c %c %c %c %c %c %c %c %c %c\n",
    //         c11,c12,ss11,ss12,w1,c21,c22,ss21,ss22,w2);
    // cout << c1<<' ' << s1<<' ' << c2<<' ' << s2<<'\n';
    if(c1==c2)
    {
        a=1;
        if(s1==s2)
        {
            b=1;
            if(((w1=='D'||w1=='F')&&(w2=='D'||w2=='F'))||
               ((w1=='A'||w1=='B'||w1=='C')&&(w2=='A'||w2=='B'||w2=='C')))
            {
                c=1;
                if(abs(w1-w2)==1)
                {
                    d=1;
                }
            }
        }
    }
    printf("%d%d%d%d",a,b,c,d);
}