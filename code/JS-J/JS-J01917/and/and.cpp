#include<bits/stdc++.h>
using namespace std;

bool a[200010][31];
bool mark[200010];
bool f[200010];

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for(int i = 1; i<=n; i++)
    {
        int x;
        cin >> x;
        int id = 31;
        while(x!=0)
        {
            a[i][--id] = x%2;
            x/=2;
        }
    }
    int p = pow(2,30);
    int ans = 0;
    for(int i = 0; i<31; i++)
    {
        int sum = 0;
        for(int j = 1; j<=n; j++)
        {
            if(!mark[j] && a[j][i])
            {
                sum++;
            }
            else
            {
                f[j] = true;
            }
        }
        if(sum>=m)
        {
            ans+=p;
            for(int j = 1; j<=n; j++)
            {
                if(f[j])
                {
                    mark[j] = true;
                }
            }
        }
        for(int j = 1; j<=n; j++)
        {
            f[j] = false;
        }
        p/=2;
    }
    cout << ans;
    return 0;
}
