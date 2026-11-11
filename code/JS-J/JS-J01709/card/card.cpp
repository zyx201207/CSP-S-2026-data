#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[200010];
long long ans[210];
int pos[201];
int s[210];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(int i = 0;i < n;i++)
    {
        cin >> a[i];
    }
    if(m == 1)
    {
        cout << n;
        return 0;
    }
    if(m == 2)
    {
        int sum1 = 0,sum2 = 0;
        for(int i = 0;i < n;i++)
        {
            if(a[i] == a[n - 1])
            {
                if(a[i] == 1) sum1++;
                else sum2++;
            }
            else
            {
                sum1++;
                sum2++;
            }
        }
        cout << sum1 << " " << sum2;
        return 0;
    }
    for(int i = 0;i < n;i++)
    {
        int sum = 0;
        for(int j = i;j < n;j++)
        {
            if(pos[a[j]])
            {
                for(int k = 0;k < m;j++)
                {
                    pos[k] = 0;
                }
                for(int k = 0;k < sum;k++)
                {
                    pos[s[k]] = 1;
                    if(s[k] == a[j]) sum = k + 1;
                }
            }
            else
            {
                pos[a[j]] = 1;
                s[sum] = a[i];
                sum++;
            }
        }
        for(int j = 0;j < m;j++)
        {
            if(pos[j]) ans[j]++;
        }
    }
    for(int i = 0;i < m - 1;i++)
    {
        cout << ans[i] << " ";
    }
    cout << ans[m - 1];
    return 0;
}
