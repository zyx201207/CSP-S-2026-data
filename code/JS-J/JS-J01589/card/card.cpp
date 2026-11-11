#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,a[500005]={};
    cin >> n >> m;
    for (int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    int cnt[300005]={};
    for (int t=1;t<=n;t++)
    {
        stack<int> s;
        bool ins[300005]={};
        for (int i=t;i<=n;i++)
        {
            if (ins[a[i]])
            {
                while (s.top()!=a[i])
                {
                    ins[s.top()] = 0;
                    s.pop();
                }
            }
            else
            {
                s.push(a[i]);
                ins[a[i]] = 1;
            }
        }
        while(s.size())
        {
            cnt[s.top()]++;
            s.pop();
        }
    }
    for (int i=1;i<=m;i++)
    {
        cout << cnt[i] << " ";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
