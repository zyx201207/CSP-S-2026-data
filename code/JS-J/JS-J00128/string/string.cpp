#include<bits/stdc++.h>
using namespace std;
struct st
{
    int num;
    char c;
}a[200005];
int n,i,j,ti,tj;
long long cnt,ans[105];
bool flag;
void add(long long n)
{
    int w = 0,nn;
    for(int i = 1;i <= 100;i++)
    {
        nn = n % 10;
        ans[i] = ans[i] + nn + w;
        if(ans[i] >= 10)
        {
            ans[i] -= 10;
            w = 1;
        }
        else
        {
            w = 0;
        }
        n /= 10;
    }
}
int  main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i].num >> a[i].c;
        cnt = (a[i].num + cnt) % 2;
    }
    if(cnt == 1)
    {
        i = 1;
        j = n;
        ti = 0;
        tj = 0;
        while(i < j - 1)
        {
            if(a[i].num - ti == a[j].num - tj)
            {
                if(a[i].c != a[j].c) add(a[i].num - ti);
                ti = 0;
                tj = 0;
                i++;
                j--;
            }
            else if(a[i].num - ti > a[j].num - tj)
            {
                ti += a[j].num - tj;
                if(a[i].c != a[j].c) add(a[j].num - tj);
                tj = 0;
                j--;
            }
            else
            {
                tj += a[i].num - ti;
                if(a[i].c != a[j].c) add(a[i].num - ti);
                ti = 0;
                i++;
            }
        }
       add(abs(ti - tj));
    }
    else
    {
        i = 1;
        j = n;
        ti = 0;
        tj = 0;
        while(i < j)
        {
            if(a[i].num - ti == a[j].num - tj)
            {
                if(a[i].c != a[j].c) add(a[i].num - ti);
                ti = 0;
                tj = 0;
                i++;
                j--;
            }
            else if(a[i].num - ti > a[j].num - tj)
            {
                ti += a[j].num - tj;
                if(a[i].c != a[j].c) add(a[j].num - tj);
                tj = 0;
                j--;
            }
            else
            {
                tj += a[i].num - ti;
                if(a[i].c != a[j].c) add(a[i].num - ti);
                ti = 0;
                i++;
            }
        }
        add(abs(ti - tj));
    }
    bool f = false;
    for(int i = 100;i >= 1;i--)
    {
        if(ans[i] != 0) f = true;
        if(f) cout << ans[i];
    }
    if(f == false) cout << 0;
    return 0;
}
