#include <algorithm>
#include <vector>
#include <iostream>



using i64 = long long;


inline i64 read()
{
        i64 x = 0, f = 1;
        char ch = getchar_unlocked();
        while(!(ch>='0' && ch<='9'))
        {
                if(ch == '-') f = -1;
                ch = getchar_unlocked();
        }
        while(ch>='0' && ch<='9')
        {
                x = (x * 10) + (ch - 48);
                ch = getchar_unlocked();
        }
        return x * f;
}

i64 max(i64 a,i64 b)
{
    return a > b ? a : b;
}

i64 ton(i64 x)
{
        return (x * (x + 1)) / 2;
}


void log(std::vector<i64> a)
{
        for(i64 &i : a) std::cout<<i<<" ";
        std::cout<<"\n";
        return ;
}


i64 get_sum(i64 l,i64 r,std::vector<i64> c)
{
        i64 sum = 0;
        for(i64 i=0;i<=r-l;i++) sum+=c[i+l] * i;
        return sum;
}

i64 get_ans(i64 l,i64 r,std::vector<i64> &ppre,std::vector<i64> &cpre)
{
        i64 sum = (ppre[r]-ppre[l-1])-((cpre[r]-cpre[l-1])*l);
        return sum;
}

int main()
{
        freopen("crystal.in", "r", stdin);
        freopen("crystal.out", "w", stdout);
        i64 n = read();
        i64 m = read();
        std::vector<i64> a(n + 1);
        a[0] = 0;
        for(i64 i = 1;i <= n;i++)
                a[i] = read();
        //let's start with difffix
        sort(a.begin() + 1, a.end());


        std::vector<i64> c(n + 1);//c <= difffix array
        for(i64 i = 1;i <= n;i++)
                c[i] = abs(a[i] - a[i-1]);
        std::vector<i64> p(n + 1);
        for(i64 i = 1;i <= n;i++)
                p[i] = c[i]*i;/*that's right,the multiPLY array*/


        std::vector<i64> cpre(n + 1);
        for(i64 i = 1;i <= n;i++)
                cpre[i] = c[i] +cpre[i-1];
        std::vector<i64> ppre(n + 1);
        for(i64 i = 1;i <= n;i++)
                ppre[i] = p[i] +ppre[i-1];
        //then we use two-pointer to find the shortest [l,r] to fit m
        i64 l = 1, r = 1;
        i64 sum = 0;
        /*while(l<=n&&r<=n)
        {
                while(1)
                {
                if(r + 1 <= n && get_sum(l,r + 1,c)<=m)
                        r++;
                    else break;
                }
                sum = max(sum, r - l + 1);
                l++;
        }
        */
        while(l<=n&&r<=n)
        {
                while(1)
                {
                if(r + 1 <= n && get_ans(l,r + 1,ppre,cpre)<=m)
                        r++;
                    else break;
                }
                sum = max(sum, r - l + 1);
                l++;
        }
        std::cout<<sum<<"\n";
        return 0;
}
