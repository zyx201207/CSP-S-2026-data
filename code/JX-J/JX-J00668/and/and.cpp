#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> v(35);
int n,m,a[200005],ans;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        int x=a[i];
        for(int j=0;x;j++)
        {
            if(x%2) v[j].push_back(a[i]);
            x/=2;
        }
    }
    for(int i=30;i>=0;i--)
    {
        if(v[i].size()>=m)
        {
            ans+=pow(2,i);
            vector<int> v2=v[i];
            for(int j=30;j>=0;j--)
            {
                v[j].clear();
            }
            for(int j=0;j<v2.size();j++)
            {
                int x=v2[j];
                for(int k=0;x;k++)
                {
                    if(x%2) v[k].push_back(v2[j]);
                    x/=2;
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
