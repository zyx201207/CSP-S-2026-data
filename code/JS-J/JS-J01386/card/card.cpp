#include <bits/stdc++.h>
using namespace std;
int n,m,t;
int a[500010],card[500010];
vector<int> q;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i = 0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i = 0;i<m;i++)
    {
        for(int j = i;j<n;j++)
        {
            for(int k = 0;k<q.size();k++)
            {
                if(q[k]==a[j])
                {
                    for(int l = 0;l<=k-1;l++)
                    {
                        q.pop_back();
                    }
                    q.push_back(a[j]);
                }
                else
                {
                    q.push_back(a[j]);
                }
            }
            if(j==n)
            {
                card[q[0]]++;
            }
        }
        t++;
    }
    for(int i = 1;i<=t+10;i++)
    {
        cout<<card[i+1];
    }
    return 0;
}
