#include<bits/stdc++.h>
using namespace std;
stack<int>num;
int ans[int(5e5)+5];
bool used[int(5e5)+5];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int k[int(5e5)+5];
    for(int i = 1;i<=n;i++)
    {
        cin>>k[i];
    }
    for(int i = 1;i<=n;i++)
    {
        memset(used,0,sizeof(used));
        for(int j = i;j<=n;j++)
        {
        if(used[k[j]] == 0)
        {
            num.push(k[j]);
            used[k[j]] = 1;
        }
        else
        {
            while(num.top()!= k[j])
            {
                used[num.top()] = 0;
                num.pop();
            }
        }
        }
        for(int i = 1;i<=m;i++)
        {
            if(used[i] == 1)
            {
                ans[i]++;
            }
        }
    }
    for(int i = 1;i<=m;i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}
