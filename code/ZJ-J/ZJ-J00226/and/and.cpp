#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    for(int &i:a) cin>>i;

    int res=0;
    for(int i=31;i>=0;--i)
    {
        int c1=0;
        for(int j:a) c1+=(j>>i&1);
        if(c1>=m)
        {
            vector<int> na;
            for(int j:a)
            {
                if(j>>i&1) na.emplace_back(j);
            }
            swap(a,na);
            res+=(1<<i);
        }
    }
    cout<<res;


    return 0;
}