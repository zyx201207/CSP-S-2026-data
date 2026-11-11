#include <bits/stdc++.h>

using namespace std;

int n,m,nn;
int a[500007],lst[300007],cnt[300007];
long long sum[300007],dp[300007];

/*void add_num(int pos,int n)
{
    nn++;
    if (n == 0)
    {
        num[a[pos]]++;
    }
    else if (n == 1)
    {
        num[a[pos]]++;
        num[a[step[pos][1] - 1]]++;
    }
    else
    {
        add_num(pos,n - 1);
        add_num(step[pos][n - 1],n - 1);
    }
}

int main()
{
    //freopen("card.in","r",stdin);
    //freopen("card.out","w",stdout);
    cin >> n >> m;
    for (int i = 1;i <= n;i++)
    {
        cin >> a[i];
        lst[a[i]] = i;
    }
    for (int i = 1;i <= n;i++)
    {
        step[i][0] = lst[a[i]] + 1;
    }
    for (int j = 1;j <= 18;j++)
    {
        for (int i = 1;i <= n;i++)
        if (step[i][j - 1] > n)step[i][j] = n + 5;
        else step[i][j] = step[step[i][j - 1]][j - 1];
    }

    for (int i = 1;i <= n;i++)
    {
        int pos = i;
        for (;pos <= n;)
        {
            for (int j = 18;j >= 0;j--)
            {
                if (step[pos][j] <= n + 1)
                {
                    add_num(pos,j);
                    pos = step[pos][j];
                    break;
                }
            }
        }
    }
    for (int i = 1;i <= m;i++)
    {
        cout << num[i] << " ";
    }
    cout << endl;

    cout << nn << endl;
    return 0;
}*/

/*
10 3
3 1 2 1 3 2 3 1 2 1
*/

int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for (int i = 1;i <= n;i++)
    {
        cin >> a[i];
        lst[a[i]] = i;
        cnt[a[i]]++;
    }
    vector<pair<int,int> >p;//last,num
    for (int i = 1;i <= m;i++)
    {
        p.push_back(make_pair(lst[i],i));
    }
    sort(p.begin(),p.end());
    //for (int i = 0;i < m;i++)
    //{
    //    cout << p[i].second << endl;
    //}
    for (int i = 0;i < m;i++)
    {
        dp[p[i].second] += cnt[p[i].second];
        if (p[i].first + 1 <= n)dp[a[p[i].first + 1]] += dp[p[i].second];
    }
    //for (int i = 1;i <= m;i++)
    //    cout << dp[i] << " ";
    //cout << endl;
    sum[p[0].second] = dp[p[0].second];
    for (int i = 1;i < m;i++)
    {
        if (p[i].first == p[i - 1].first + 1)sum[p[i].second] = sum[p[i - 1].second] + dp[p[i].second];
        else sum[p[i].second] = dp[p[i].second];
    }
    for (int i = 1;i <= m;i++)
    {
        cout << dp[i] << " ";
    }
    cout << endl;
}
