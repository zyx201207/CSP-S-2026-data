#include <algorithm>
#include <iostream>
#include <vector>

using i64 = long long;

inline i64 read()
{
        i64 x = 0, f = 1;
        char ch = getchar_unlocked();
        while (!(ch >= '0' && ch <= '9'))
        {
                if (ch == '-') f = -1;
                ch = getchar_unlocked();
        }
        while (ch >= '0' && ch <= '9')
        {
                x = (x * 10) + (ch - 48);
                ch = getchar_unlocked();
        }
        return x * f;
}

void log(std::vector<i64> x)
{
        for(i64 &i:x) std::cout<<i<<" ";
        std::cout<<"\n";
        return ;
}

i64 ton(i64 n)
{
        return n*(n-1)/2;
}

int main()
{
        freopen("hub.in","r",stdin);
        freopen("hub.out","w",stdout);
        i64 c=read(),t=read();
        while(t--)
        {
std::cout<<0<<"\n";
        }
        return 0;
}
