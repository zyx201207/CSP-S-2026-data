#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,ans[500005];
    cin>>n>>m;
    int a;
    queue<int> q;
    vector<int> tab;
    for(int i=1;i<=n;i++)
    {
        cin>>a;
        q.push(a);
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i-1;j++)
        {
            q.push(q.front());
            q.pop();
        }
        tab.clear();
        for(int j=i;j<=n;j++)
        {
            int k=q.front();
            q.pop();
            q.push(k);
            bool f=false;
            int kk;
            for(kk=0;kk<tab.size();kk++)
            {
                if(tab[kk]==k)
                {
                    f=true;
                    break;
                }
            }
            if(f)
            tab.erase(tab.begin()+kk,tab.end());
            tab.push_back(k);
        }
        for(int j=0;j<tab.size();j++)
            ans[tab[j]]++;
    }
    for(int i=1;i<=m;i++)
        cout<<ans[i]<<' ';
    return 0;
}
