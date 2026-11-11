#include<bits/stdc++.h>
using namespace std;
int a[100000005];
int b[100000005];
int cnt[100000005];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= n;j++)
        {
            if(a[j]==0)
            {
                continue;
            }
            for(int k = 1;k <= n;k++)
            {
                int c = 0;
                if(a[k]==a[j]&&a[j]!=0)
                {
                    for(int x = k;x < j;x++)
                    {
                        b[x+1]=a[x];
                        a[x]=0;
                        c = x;
                    }
                }
                cnt[a[i]]++;
                for(int x = c;x < j;x++)
                {
                    a[x]=b[x+1];
                }
            }
        }

    }

    for(int i = 1;i <= m;i++)
    {
        cout << cnt[i];
    }
}
