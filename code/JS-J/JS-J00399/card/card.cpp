#include<bits/stdc++.h>
using namespace std;
queue<int> q;
int n,m,a[500010],appear[300010],sz[300010];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    q.push(a[1]);
    appear[a[1]]++;
    sz[a[1]]=1;
    for(int i=2;i<=n;i++)
    {
        bool flag=1;
        for(int j=1;j<i;j++)
        {
            if(a[i]==a[j])
                flag=0;
        }
        if(flag)
        {
            q.push(a[i]);
            appear[a[i]]++;
            sz[a[i]]=q.size();
        }
        else
        {
            while(q.size()>=sz[a[i-1]])
                q.pop();
            q.push(a[i]);
            appear[a[i]]++;
            sz[a[i]]=q.size();
        }
    }
    for(int i=1;i<=m;i++)
        cout<<appear[i]<<" ";
    cout<<endl;
    return 0;
}
