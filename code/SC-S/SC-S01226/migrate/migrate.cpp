#include <iostream>
#include <cstring>
using namespace std;
const long long N = 2e6 + 5;
int c,t;
long long n,d,x[N],temp[N];
void dfs(int l, int r, int step)
{
    if(l == r)
    {
        temp[step]++;
        return;
    }
    if(x[l+1] - x[l] > d) return;
    for(int i = l + 1 ; i <= r ; i++)
    {
        if(x[i] - x[l] <= d) dfs(i, r, step + 1);
    }
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> c >> t;
    while(t--)
    {
        memset(temp, 0, sizeof(temp));
        cin >> n >> d;
        for(int i = 1 ; i <= n ; i++) cin >> x[i];
        long long cnt = 0;
        for(int i = 1 ; i < n ; i++)
        {
            for(int j = i + 1 ; j <= n ; j++)
            {
                memset(temp, 0, sizeof(temp));
                dfs(i,j,0);
                for(int k = 1 ; k <= j - i ; k++)
                {
                    if(temp[k] == 2)
                    {
                        cnt++;
                        break;
                    }
                    if(temp[k] > 0) break;
                }
            }
        }
        cout <<cnt << '\n';
    }
    return 0;
}
