#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin >> n >> m;
    int a[n+5],b[m+5];
    for(int i = 1;i<=n;i++)
    {
        cin >> a[i];
    }
    vector<int>v;
    v.push_back(0);
    for(int i = 1;i<=n ;i++)
    {
        for(int j = 0;j<v.size();j++)
        {
            int num;
            if(a[i]==v[j])
            {
                num=j;
                for(int k = num;k<v.size();k++)
                {
                    v.pop_back();
                }
            }
        }
        v.push_back(a[i]);
    }
    sort(v.begin(),v.end());
    for(int j = 0;j<v.size();j++)
    {
        b[v[j]]++;
    }
    for(int i = 1;i<=m;i++)
    {
        cout<<b[i]<<" ";
    }
    return 0;
}
