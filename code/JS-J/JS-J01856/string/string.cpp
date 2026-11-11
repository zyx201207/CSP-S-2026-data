#include<iostream>
#define int long long
#define AK return
#define CSP 0;
using namespace std;
int a[200005],l[200005],r[200005];
char c[200005],lc[200005],rc[200005];
signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    //freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen
    //freopen//freopen//freopen//freopen//fuckccf//freopen//freopen//freopen//freopen
    //freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen
    int n;
    cin >> n;
    int s = 0;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i] >> c[i];
        s += a[i];
    }
    int ls = 0,rs = 0,lsss = 0,rsss = 0;
    int ss = 0;
    for(int i = 1;i <= n;i++)
    {
        if(s % 2 == 0)
        {
            if(ss >= s/2)
            {
                r[rs] = a[i];
                rc[rs] = c[i];
                rs++;
                rsss += a[i];
            }
            else if(ss + a[i] > s/2)
            {
                l[ls] = (s/2)-ss;
                lc[ls] = c[i];
                ls++;
                lsss += (s/2)-ss;
                r[rs] = a[i]+ss-(s/2);
                rc[rs] = c[i];
                rs++;
                rsss += a[i]+ss-(s/2);
            }
            else
            {
                l[ls] = a[i];
                lc[ls] = c[i];
                ls++;
                lsss += a[i];
            }
        }
        else
        {
            if(ss >= (s+1)/2)
            {
                r[rs] = a[i];
                rc[rs] = c[i];
                rs++;
                rsss += a[i];
            }
            else if(ss+a[i] > (s+1)/2)
            {
                if(ss < s/2)
                {
                    l[ls] = (s/2)-ss;
                    lc[ls] = c[i];
                    ls++;
                    lsss += (s/2)-ss;
                }
                r[rs] = a[i]+ss-(s/2)-1;
                rc[rs] = c[i];
                rs++;
                rsss += a[i]+ss-(s/2)-1;
            }
            else if(ss+a[i] == (s+1)/2)
            {
                l[ls] = a[i]-1;
                lc[ls] = c[i];
                ls++;
                lsss += a[i]-1;
            }
            else
            {

                l[ls] = a[i];
                lc[ls] = c[i];
                ls++;
                lsss += a[i];
            }
        }
        ss += a[i];
    }
    int p = 0,lp = 0,rp = rs-1,c = 0,lss = 0,rss = 0,sss = 0;
    while(true)
    {
        if(lp < ls && (rp < 0 || lss + l[lp] < rss+r[rp]))
        {
            //cout << 'l' << lss << ' ' << rss << ' ' << l[lp];
            if(lc[lp] != rc[rp])
            {
                //cout << '+' << lss+l[lp]-max(lss,rss);
                sss += lss+l[lp]-max(lss,rss);
            }
            lss += l[lp];
            lp++;
        }
        else if(rp >= 0)
        {
            //cout << 'r' << lss << ' ' << rss << ' ' << r[rp];
            if(lc[lp] != rc[rp])
            {
                //cout << '+' << rss+r[rp]-max(lss,rss);
                sss += rss+r[rp]-max(lss,rss);
            }
            rss += r[rp];
            rp++;
            rp -= 2;
        }
        else
        {
            break;
        }
        //cout << '\n';
    }
    cout << sss;
    AK CSP
}
