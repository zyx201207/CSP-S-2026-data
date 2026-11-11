#include <bits/stdc++.h>
using namespace std;
int n,m,a[100010],t[100010];
stack <int> s;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i = 1;i <= n;i++) cin>>a[i];
    for(int i = 1;i <= m;i++)
    {
        int ans = 0;
        for(int j = 1;j <= n;j++)
        {
            for(int k = 1;k <= m;k++) t[k] = 0;
            for(int k = j;k <= n;k++)
            {
                t[a[k]]++;
                if(t[a[k]] > 1)
                {
                    t[a[k]]--;
                    while(s.top() != a[k] && !s.empty())
                    {
                        t[s.top()]--;
                        s.pop();
                    }
                }
                else s.push(a[k]);
            }
            while(!s.empty())
            {
                if(s.top() == i) ans++;
                s.pop();
            }
        }
        cout<<ans<<" ";
    }
    return 0;
}
