#include<bits/stdc++.h>
#define int short
using namespace std;
int z[500005];
int ans[300005];
bool vis[300005];
stack<int> st;
signed main()
{
   freopen("card.in","r",stdin);
   freopen("card.out","w",stdout);
   ios::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);
int n,m;
cin>>n>>m;
for(int i=0;i<n;i++)
{
    cin>>z[i];
}
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            if(vis[z[j]]==0)
            {
                st.push(z[j]);
                vis[z[j]]=1;
            }else
            {
                while(!st.empty())
                {
                    int temp=st.top();
                    if(temp==z[j])
                    break;
                    vis[temp]=0;
                    st.pop();
                }
            }
        }
         while(!st.empty())
        {
            vis[st.top()]=0;
            ans[st.top()]++;
             st.pop();
        }
    }
    for(int i=1;i<=m;i++)
    cout<<ans[i]<<" ";
}
