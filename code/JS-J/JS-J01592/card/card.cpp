#include<bits/stdc++.h>
using namespace std;
int n,m,a[600005],pos=0,tmp[600005];
bool vis[600005];
stack<int> st;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=n;i>=1;i--)
    {
        for(int j=i;j<=n;j++)
        {
            vis[a[j]]=false;
        }
        for(int j=i;j<=n;j++)
        {
            if(vis[a[j]]==0)
            {
                vis[a[j]]=true;
                st.push(a[j]);
            }
            else
            {
                while(!st.empty()&&st.top()!=a[j])
                {
                    vis[st.top()]=false;
                    st.pop();
                }
            }

        }
        while(!st.empty())
        {
            tmp[st.top()]++;
            st.pop();
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<tmp[i]<<" ";
    }
    return 0;
}
