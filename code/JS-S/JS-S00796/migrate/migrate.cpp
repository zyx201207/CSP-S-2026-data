#include <iostream>
#include <cstring>
using namespace std;
long long a[2000005],b[2000005];
int cnt,minn = 1e8,ans,pos;
void dfs(int cur,int e,int p,int n,long long d)
{

    if(cur >= e)
    {
        if (minn > p)
        {
            minn = p;
            cnt = 1;
        }
        if(minn == p) cnt++;
        return;
    }
    if (p > minn) return;

    for (int i = cur + 1;i <= n;i++)
    {
        if(a[i]- a[cur] > d)
        {
            pos = i - 1;
            break;
        }
    }

    for (long long i = cur + 1;i <= pos&& i <= n;i++)
    {
        if (b[i] == 1) continue;
        p++;
        b[i] = 1;
        dfs(i,e,p,n,d);
        b[i] = 0;
        p--;
    }
}
int main()
{
    int c,t;
    cin >> c >> t;
    while(t--)
    {
        ans = 0;
        int n;
        long long d;
        cin >> n >> d;
        for (int i = 1;i <= n;i++)
        {
            cin >> a[i];
        }
        for (int i = 1;i + 3 <= n;i++)
        {
            for (int j = i + 3;j <= n;j++)
            {
                memset(b,0,sizeof(b));
                cnt = 1;
                minn = 1e8;
                dfs(i,j,0,n,d);
                if (cnt == 2) ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
