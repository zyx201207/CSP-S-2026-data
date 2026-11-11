#include <bits/stdc++.h>
using namespace std;
int n , m;
int a[500005] , ans[300005];
int main()
{
    freopen("card.in" , "r" , stdin);
    freopen("card.out" , "w" , stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i ++)
    {
        cin >> a[i];
    }
    for(int i = 1;i <= n;i ++)
    {
        queue <int> q;
        for(int j = i;j <= n;j ++)
        {
            int len = q.size();
            bool flag = false;
            for(int k = 1;k <= len;k ++)
            {
                if(flag == true)
                {
                    q.pop();
                }
                if(flag == false)
                {
                    if(q.front() == a[j])
                    {
                        flag = true;
                        q.pop();
                    }
                    else
                    {
                        q.push(q.front());
                        q.pop();
                    }
                }
            }
            q.push(a[j]);
        }
        while(!q.empty())
        {
            ans[q.front()] ++;
            q.pop();
        }
    }
    for(int i = 1;i <= m;i ++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}
