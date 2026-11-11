#include<bits/stdc++.h>
using namespace std;

int a[500001],s[300001],ans[300001];
bool f[300001],g[300001];

int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        s[a[i]]++;
    }
    stack<int>q;
    vector<int>t;
    for(int i=n-1;i>=0;i--)
    {
        if(!f[a[i]])
        {
            q.push(a[i]);
            f[a[i]]=1;
        }else{
            while(q.top()!=a[i])
            {
                f[q.top()]=0;
                q.pop();
            }
        }
        if(!g[a[i]])
        {
            g[a[i]]=1;
            while(!q.empty())
            {
                t.push_back(q.top());
                ans[q.top()]+=s[a[i]];
                q.pop();
            }
            for(int j=t.size()-1;j>=0;j--)
            {
                q.push(t[j]);
            }
            t.clear();
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<ans[i]<<' ';
    }
    return 0;
}
