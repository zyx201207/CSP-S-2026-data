#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],re[300010];
bool used[300010];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        queue<int> q;
        stack<int> st;
        memset(used,0,sizeof(used));
        for(int j=i;j<=n;j++)
        {
            q.push(a[j]);
        }
        while(!q.empty())
        {
            int ne=q.front();
            q.pop();
            if(used[ne])
            {
                while(st.top()!=ne)
                {
                    st.pop();
                }
                st.pop();
            }
            st.push(ne);
            used[ne]=true;
        }
        while(!st.empty())
        {
            re[st.top()]++;
            st.pop();
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<re[i]<<" ";
    }
    cout<<endl;
    return 0;
}
