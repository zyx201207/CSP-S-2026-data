#include <iostream>
#include <cstdio>
using namespace std;
long long read()
{
    long long sum = 0;
    int f = 1;
    char ch = getchar();
    if(ch < '0' || ch > '9')
    {
        f = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9')
    {
        int x = ch - '0';
        sum = sum * 10 + x;
        ch = getchar();
    }
    return 1ll * f * sum;
}

int main()
{
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    int c = read(), t = read();

    fclose(stdin);
    fclose(stdout);
    return 0;
}
