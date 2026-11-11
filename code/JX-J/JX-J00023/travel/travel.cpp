#include<bits/stdc++.h>
using namespace std;
struct node
{
    int n,m,num;
    char c;
}a,b;
bool check(char c)
{
    if(c == 'A' || c == 'B' || c == 'C') return 0;
    else return 1;
}
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    scanf("%d%d",&a.n,&a.m);
    cin >> a.c;
    a.num = check(a.c);
    scanf("%d%d",&b.n,&b.m);
    cin >> b.c;
    b.num = check(b.c);
    if(a.n != b.n)
    {
        puts("0000");
        return 0;
    }
    if(a.m != b.m)
    {
        puts("1000");
        return 0;
    }
    if(a.num != b.num)
    {
        puts("1100");
        return 0;
    }
    if(!a.num)
    {
        if(abs(((int)a.c) - ((int)b.c)) != 1)
        {
            puts("1110");
            return 0;
        }  
    }
    puts("1111");
    return 0;
}