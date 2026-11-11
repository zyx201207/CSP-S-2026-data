#include<bits/stdc++.h>
using namespace std;
int a[500005];
int ans[300005],vis[300005];
stack<int> st;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;cin >> n >> m;
    for(int i = 1;i <= n;i++)cin >> a[i];
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= m;j++)vis[j] = 0;
        for(int j = i;j <= n;j++)
        {
            if(vis[a[j]] == 0)
            {
                st.push(a[j]);
                vis[a[j]] = 1;
            }
            else
            {
                while(st.top() != a[j])
                {
                    vis[st.top()] = 0;
                    st.pop();
                }
            }
        }
        for(int j = 1;j <= m;j++)
            if(vis[j] == 1)ans[j]++;
    }
    for(int i = 1;i <= m-1;i++)cout << ans[i] << " ";
    cout << ans[m];
    return 0;
}
