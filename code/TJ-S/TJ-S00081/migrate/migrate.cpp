#include <bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[2000005],cnt;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> c >> t;
    for(int i = 1;i <= t;i++)
    {
        cin >> n >> d;
        for(int j = 1;j <= n;j++)
        {
            cin >> a[j];
        }
        cnt = 0;
        for(int j = 1;j <= n;j++)
        {
            for(int k = j + 1;k <= n;k++)
            {
                if(a[k] - a[j] <= d)
                {
                    continue;
                }
                else
                {
                    if((a[k] - a[j] + 1) % d == 0)
                    {
                        //cout << a[k] << " " << a[j] << endl;
                        cnt++;
                    }
                }
            }
        }
        cout << cnt << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
