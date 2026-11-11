#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long sum[300005];
stack<long long> st;
bool vis[300005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            if(vis[a[j]]==true)
            {
                while(!st.empty())
                {
                    if(st.top()==a[j])
                    {
                        st.pop();
                        break;
                    }
                    else
                    {
                        vis[st.top()]=false;
                        st.pop();
                    }
                }
            }
            else
            {
                vis[a[j]]=true;
            }
            st.push(a[j]);
        }
        while(!st.empty())
        {
            sum[st.top()]++;
            st.pop();
        }
        memset(vis,false,sizeof(vis));
    }
    for(int i=1;i<=m;i++)
    {
        cout<<sum[i]<<' ';
    }
    return 0;
}
