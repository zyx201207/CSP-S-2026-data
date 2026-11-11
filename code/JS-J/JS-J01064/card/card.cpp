#include<bits/stdc++.h>
using namespace std;
bool Find(stack<int> q,int x)
{
    while(!q.empty())
    {
        int t=q.top();
        q.pop();
        if(t==x)
            return true;
    }
    return false;
}
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n,m; cin>>n>>m;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    int b[m]={0},k=1;
    for(int i=0;i<n;i++)
    {
        stack<int> q;
        for(int j=i;j<n;j++)
        {
            if(Find(q,a[j])==true)
            {
                int t=-1;
                while(t!=a[j])
                {
                    t=q.top(); q.pop();
                }
            }
            q.push(a[j]);
        }
        while(!q.empty())
        {
            int t=q.top(); q.pop();
            b[t-1]++;
        }
    }
    for(int i=0;i<m;i++)
        cout<<b[i]<<" ";
    return 0;
}
