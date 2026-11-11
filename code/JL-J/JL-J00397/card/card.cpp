#include<bits/stdc++.h>
using namespace std;
const int N = 500010;
int a[N],b[N];
int sum[N];
int n,m;
int p;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n;i ++)
    {
        cin >> a[i];
    }
    for(int i = 1;i <= n;i ++)
    {
        for(int j = i;j <= n;j ++)
        {
            for(int k = 0;k < p;k ++)
            {
                if(b[k] == a[j])
                {
                    p = k;
                }
            }
            b[p ++] = a[j];
        }
        for(int j = 0;j < p;j ++)
        {
            sum[b[j]] ++;
        }
        while(p --) b[p] = 0;
        p = 0;
    }
    for(int i = 1;i <= m;i ++)
    {
        cout << sum[i] << ' ';
    }
    return 0;
}
