#include <bits/stdc++.h>
using namespace std;
long long n,m,a[200005],maxx=-1;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    vector<vector<int>> v(100000);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            v[i].push_back(abs(a[i]-a[j]));
        }
    }
    for(int i=0;i<n;i++)
    {
        sort(v[i].begin(),v[i].end());
    }
    for(int i=0;i<n;i++)
    {
        long long ll=m,sum=0;
        for(int j=0;j<n;j++)
        {
            if(ll>=v[i][j])
            {
                ll-=v[i][j];
                sum++;
            }else break;
        }
        maxx=max(maxx,sum);
    }
    cout<<maxx;
    return 0;
}
