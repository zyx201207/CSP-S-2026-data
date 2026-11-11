#include<bits/stdc++.h>
using namespace std;
int n, m, a[200005];
vector<int>vec,tmp;
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    freopen("and.in","r",stdin);
    freopen("ans.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i],vec.push_back(a[i]);
    int ans=0;
    for(int i=30;i>=0;i--)
    {
        int res=0;
        tmp.clear();
        for(int j:vec)if(j&(1<<i))res++,tmp.push_back(j);
        if(res>=m)
        {
            vec.clear();
            for(int j:tmp)vec.push_back(j);
            ans+=(1<<i);
        }
    }
    cout<<ans<<"\n";
}