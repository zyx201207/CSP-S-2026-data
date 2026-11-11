#include<bits/stdc++.h>
using namespace std;
int a[200005];
int c[200005][40];
int used[200005];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,m;
    cin >> n >> m;
    for(int i = 1;i<=n;i++)
    {
        cin >> a[i];
        int x = a[i];
        int j = 0;
        while(x)
        {
            c[i][++j] = x%2;
            c[0][j]+=x%2;
            x/=2;
        }
    }

    int ans = 0;
    for(int i = 31;i>=1;i--)
    {
        if(c[0][i]>=m)
        {
            ans*=2;
            ans++;
            for(int j=1;j<=n;j++)
            {
                if(c[j][i]||used[j])continue;
                //cout << i << " ";
                used[j] = 1;
                for(int k = 1;k<=31;k++)
                {
                    c[0][k]-=c[j][k];
                }
            }
            //cout << endl;
        }
        if(c[0][i]<m)
        {
            ans*=2;
        }
    }
    cout << ans << endl;
    return 0;
}
