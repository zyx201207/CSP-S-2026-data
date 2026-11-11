#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,m;
vector<int> arr;
vector<int> target;
int ans;

signed main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i = 1;i <= n;i++)
    {
        int x;
        cin>>x;
        arr.emplace_back(x);
    }
    for(int id = 30;id >= 0;id--)
    {
        vector<int> tmp;
        for(int i : arr) if((i >> id) & 1) tmp.emplace_back(i);
        if(tmp.size() < m) continue;
        else
        {
            arr = tmp;
            ans |= 1 << id;
        }
    }
    cout<<ans<<"\n";
}