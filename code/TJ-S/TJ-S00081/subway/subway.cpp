#include <bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,a[500005],k[505],s[505][50005],t[505][50005],x,y,used[505],z,cnt,visa[505],visb[505],visc,visd,p[505];
bool e = false,f = false;
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1;i <= m;i++)
    {
        cin >> a[i];
    }
    for(int i = 1;i <= n;i++)
    {
        cin >> k[i];
        for(int j = 1;j <= k[i];j++)
        {
            cin >> s[i][j] >> t[i][j];
        }
    }
    for(int i = 1;i <= q;i++)
    {
        cin >> x >> y;
        cnt = 0;
        for(int j = 1;j <= n;j++)
        {
            e = false,f = false;
            for(int l = 1;l <= k[j];l++)
            {
                if(s[j][l] == x)
                {
                    e = true;
                }
                if(s[j][l] == y)
                {
                    f = true;
                }
            }
            if(e == true && f == true)
            {
                z++;
                used[z] = j;
            }
            if(e == true && f == false)
            {
                visc++;
                visa[visc] = j;
            }
            if(e == false && f == true)
            {
                visd++;
                visb[visd] = j;
            }
        }
        if(z != 0)
        {
            long long minn = 0;
            cnt = 100000;
            for(int j = 1;j <= z;j++)
            {
                for(int l = 1;l <= k[j];l++)
                {
                    if(s[j][l] == x || s[j][l] == y)
                    {
                        minn += t[j][l];
                    }
                }
                cnt = min(cnt,minn);
            }
            cout << cnt + a[x] + a[y] << endl;
        }
        else
        {
            cnt = 100000;
            for(int j = 1;j <= visc;j++)
            {
                for(int l = 1;l <= visd;l++)
                {
                    long long minn = 0;
                    if(visa[j] != visb[l])
                    {
                        for(int g = 1;g <= k[visa[j]];g++)
                        {
                            p[s[visa[j]][g]]++;
                        }
                        for(int g = 1;g <= k[visb[l]];g++)
                        {
                            p[s[visb[l]][g]]++;
                        }
                        for(int g = 1;g <= n;g++)
                        {
                            if(p[g] == 2)
                            {
                                for(int h = 1;h <= k[visa[j]];h++)
                                {
                                    if(g == s[visa[j]][h])
                                    {
                                        minn += t[visa[j]][h];
                                    }
                                    if(x == s[visa[j]][h])
                                    {
                                        minn += t[visa[j]][h];
                                    }
                                }
                                //cout << minn << endl;
                                for(int h = 1;h <= k[visb[l]];h++)
                                {
                                    if(g == s[visb[l]][h])
                                    {
                                        minn += t[visb[l]][h];
                                    }
                                    if(y == s[visb[l]][h])
                                    {
                                        minn += t[visb[l]][h];
                                    }
                                }
                                //cout << minn << endl;
                            }
                        }
                        cnt = min(cnt,minn);
                    }
                }
            }
            cout << cnt + a[x] + a[y] << endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
