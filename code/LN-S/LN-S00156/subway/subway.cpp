#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[100005],a[10005],k[10005][10005],x[1005][2],t = 0,numk[10005],sub[10005][20],sub1[10005]={0},ans = 0,ans1 = 0;
int ttime(int d)
{

}
int main()
{
    freopen("subway.in" ,"r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> q;
    for(int i = 0;i < m;i ++)
    {
        cin >> w[i];
    }
    int ttt;
    for(int i = 0;i < n;i ++)
    {
        ttt = 0;
        cin >> a[i];
        for(int j = 0;j < a[i];j ++)
        {
            cin >> k[j][0] >> k[j][1];
            numk[k[j][0]] ++;
            sub[k[j][0]][sub1[k[j][0]]] = i;
            sub1[k[j][0]] ++;
        }
    }
    for(int i = 0;i < q;i ++)
    {
        cin >> x[i][0] >> x[i][2];
    }
    if(n == 3)
    {

    }
    if(n == 2)
    {
        for(int i = 0;i < q;i ++)
        {
            for(int j = 0;j < m;j ++)
            {
                t = w[x[j][0] - 1] + w[x[j][1] - 1];
                if(numk[i] >= 2)
                {
                    ans += k[0][i] + k[1][i];
                }
                ans1 = max(ans1,ans);
            }
            cout << t + ans;
        }
        return 0;
    }
    for(int i = 0;i < q;i ++)
    {
        ans = 0;
        t = w[x[i][0] - 1] + w[x[i][1] - 1];
        cout << ttime(w[i]);
    }

    return 0;
}

