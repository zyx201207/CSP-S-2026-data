#include<bits/stdc++.h>
using namespace std;
#define int long long
#define itn long long
#define pii pair<int,int>
int fread()
{
    int fh = 1,res = 0;
    char c = getchar();
    while(c == '\n' || c == ' ' || c == '\r' || c == '\t') c = getchar();
    while(c == '-') fh = -fh,c = getchar();
    while(c >= '0' && c <= '9') res = res * 10 + (c - '0'),c = getchar();
    return fh * res;
}
void fwrite(int _a)
{
    char _c[64];
    int cnt = 0;
    if(_a == 0)
    {
        putchar('0');
        return;
    }
    if(_a < 0)
    {
        putchar('-');
        _a = -_a;
    }
    while(_a)
    {
        _c[cnt] = _a % 10 + '0';
        _a /= 10;
        cnt++;
    }
    for(int i = cnt - 1;i >= 0;i--)
    {
        putchar(_c[i]);
    }
}
signed main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    
}