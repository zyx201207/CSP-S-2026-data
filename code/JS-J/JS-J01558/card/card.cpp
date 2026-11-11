#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],ans[500005];
bool flag[300005];
stack<int> st;
void solve(int pos)
{
    while(!st.empty())
    {
        st.pop();
    }
    memset(flag,0,sizeof(flag));
    st.push(a[pos]);
    flag[a[pos]]=1;
    for(int i=pos;i<=n;i++)
    {
        if(flag[a[i]])
        {
            while(flag[a[i]])
            {
                flag[st.top()]=0;
                st.pop();
            }
            st.push(a[i]);
        }
        else st.push(a[i]);
        flag[a[i]]=1;
    }
    for(int i=1;i<=m;i++)
    {
        if(flag[i]==1)ans[i]++;
    }
}
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        solve(i);
    }
    for(int i=1;i<=m;i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}
