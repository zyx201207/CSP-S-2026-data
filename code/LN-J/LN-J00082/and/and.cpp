#include <bits/stdc++.h>
using namespace std;
string s[1000005],b;
long long sum[1000005];
void check(long long x,long long y)
{
    while(x>0)
    {
        if (x%2==0)
        {
            s[y]+="0";
        }
        else
        {
            s[y]+="1";
        }
        x/=2;
    }
    reverse(s[y].begin(),s[y].end());
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m,a[1000005],ans=0,t,r=1;

    cin >> n >> m;
    for (long long i = 1;i <= n;i++)
    {
        cin >> a[i];
        check(a[i],i);
    }
    for (long long i = 1;i <= n-1;i++)
    {
        b=s[i];
        t=m-1;
        while(t--)
        {
            for (long long j = i+1;j <= n;j++)
            {
                for (long long k = 0;k < min(s[i].length(),s[j].length());k++)
                {
                    if (b[k]=='1'&&s[j][k]=='1')
                    {
                        b[k]='1';
                    }
                    else{
                        b[k]='0';
                    }

                }
                if (t==0)
                {
                    reverse(b.begin(),b.end());
                    long long x=0,v=1;
                    while(x<b.length())
                    {
                        sum[r]+=(b[x]-'0')*v;
                        v*=2;
                        x++;
                    }
                    r++;
                    reverse(b.begin(),b.end());
                }

            }

        }
    }
    for (long long i = 1;i <= r;i++)
    {
        ans=max(ans,sum[i]);
    }
    cout << ans;
    return 0;
}
