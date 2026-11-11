#include<bits/stdc++.h>
using namespace std;
int m,n,a[1000000],cnt,ans[1000000];
int q[10000];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
        cin >> a[i];
    for(int i = 1;i<= n;i++)
    {
        for(int j = i;j<= n;j++)
        {
            for(int k = 0;k <= n;k++)
            {
                if(q[k] == a[j])
                    for(int l = k;l <= n;l++)
                        q[l] = 0;
            }
            q[j] = a[j];
        }
        for(int k = 0;k <= n;k++)
            if(q[k] != 0)
                ans[q[k]]++;
    }
    for(int i = 1;i <= m;i++)
        cout << ans[i] << ' ';
    return 0;
}
