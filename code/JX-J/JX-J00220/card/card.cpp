#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010],tot[300010];
inline void solve(int o)
{
    set<int>st;
    stack<int>ln;
    for(int i=o;i<=n;++i)
    {
        if(st.count(a[i]))
        {
            while(ln.top()!=a[i])
            {
                st.erase(ln.top());
                ln.pop();
            }
        }
        else
        {
            ln.push(a[i]);
            st.insert(a[i]);
        }
    }
    while(!ln.empty())
    {
        tot[ln.top()]++;
        ln.pop();
    }
}
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;++i)
    {
        solve(i);
    }
    for(int i=1;i<=m;++i)
    {
        cout<<tot[i]<<" ";
    }
    return 0;
}
