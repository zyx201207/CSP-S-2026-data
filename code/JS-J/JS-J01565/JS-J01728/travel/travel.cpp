#include <bits/stdc++.h>
using namespace std;
int lett[6]={1,2,3,5,-999,6};
int getlws()
{
    int a;
    char c;
    cin >> c;
    a = c-48;
    cin >> c;
    a = 10*a+c-48;
    return a;
}

int getlet()
{
    return lett[getchar()-'A'];
}

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int r[4]={0,getlws(),getlws(),getlet()},x[4]={0,getlws(),getlws(),getlet()};
    if(r[1]^x[1]) printf("0000");
    else if(r[2]^x[2]) printf("1000");
    else if((r[3]<4)^(x[3]<4)) printf("1100");
    else if(abs(r[3]-x[3]) ^ 1) printf("1110");
    else printf("1111");
    return 0;
}
