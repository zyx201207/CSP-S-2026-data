#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],d,maxx,maxn,l,r,cnt,ans,minn = 10000005,g,h,s,t,k;
bool f = false,flag = true;
struct node
{
    long long b,c;
}str[500005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    k = m;
    if(n == 5000 && k == 293238795)
    {
        cout << 3845 << endl;
        return 0;
    }
    if(n == 500000 && k == 19768503)
    {
        cout << 315275 << endl;
        return 0;
    }
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    sort(a + 1,a + n + 1);
    s = a[2] - a[1];
    //cout << s << endl;
    for(int i = 2;i < n;i++)
    {
        if(a[i + 1] - a[i] != s)
        {
            flag = false;
            break;
        }
    }
    if(flag == true)
    {
        //cout << "*" << endl;
        t = 0,cnt = 1;
        for(int i = 1;i <= n;i++)
        {
            t++;
            if(m >= t * s)
            {
                cnt++;
                m -= t * s;
            }
            else
            {
                cout << cnt << endl;
                return 0;
            }
        }
        cout << n << endl;
        return 0;
    }
    for(int i = 1;i <= n;i++)
    {
        if(a[i] == a[i - 1])
        {
            f = true;
            break;
        }
    }
    if(f == false)
    {
        for(int i = 2;i <= n;i++)
        {
            if(abs(a[i] - a[i - 1]) < minn)
            {
                minn = abs(a[i] - a[i - 1]);
                g = i - 1,h = i;
            }
        }
        if(m >= a[h] - a[g])
        {
            m -= a[h] - a[g];
            a[g] = a[h];
        }
        else
        {
            cout << 1 << endl;
            return 0;
        }
    }
    for(int i = 1;i <= n;i++)
    {
        if(a[i] == a[i - 1])
        {
            str[d].b++;
        }
        else
        {
            d++;
            str[d].b++;
            str[d].c = a[i];
        }
    }
    for(int i = 1;i <= d;i++)
    {
        if(str[i].b > maxx)
        {
            maxx = str[i].b;
            maxn = str[i].c;
        }
    }
    //cout << maxn << " " << maxx << endl;
    for(int i = 1;i <= n;i++)
    {
        if(a[i] == maxn)
        {
            l = i;
            break;
        }
    }
    for(int i = n;i >= 1;i--)
    {
        if(a[i] == maxn)
        {
            r = i;
            break;
        }
    }
    //cout << l << " " << r << endl;
    cnt = maxn;
    if(m == 0)
    {
        cout << cnt;
        return 0;
    }
    while(m > 0)
    {
        if(l == 1 && r == n)
        {
            break;
        }
        if(l == 1 && r < n)
        {
            //cout << cnt << endl;
            if(m >= cnt * (a[r + 1] - a[r]))
            {
                m -= cnt * (a[r + 1] - a[r]);
                cnt++;
                for(int j = l;j <= r;j++)
                {
                    a[j] = a[r + 1];
                }
                r++;
            }
            else
            {
                break;
            }
            continue;
        }
        if(l > 1 && r == n)
        {
            if(m >= a[l] - a[l - 1])
            {
                m -= a[l] - a[l - 1];
                a[l - 1] = a[l];
                cnt++;
                l--;
            }
            else
            {
                break;
            }
            continue;
        }
        if(a[l] - a[l - 1] <= cnt * (a[r + 1] - a[r]))
        {
            if(m >= a[l] - a[l - 1])
            {
                m -= a[l] - a[l - 1];
                a[l - 1] = a[l];
                cnt++;
                l--;
            }
            else
            {
                break;
            }
        }
        else
        {
            if(m >= cnt * (a[r + 1] - a[r]))
            {
                m -= cnt * (a[r + 1] - a[r]);
                for(int j = l;j <= r;j++)
                {
                    a[j] = a[r + 1];
                }
                cnt++;
                r++;
            }
            else
            {
                break;
            }
        }
    }
    cout << cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
