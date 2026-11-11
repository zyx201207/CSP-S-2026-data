#include<bits/stdc++.h>
#define int long long
using namespace std;

int n;
vector<pair<int,char>> vec;
vector<pair<int,char>> pos;
int l,r;
int ans;

signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i = 1;i <= n;i++)
    {
        int x;
        char c;
        cin>>x>>c;
        vec.emplace_back(x,c);
    }
    pos.emplace_back(vec[0]);
    for(int i = 1;i < vec.size();i++)
    {
        pos.emplace_back(pos[i - 1].first + vec[i].first,vec[i].second);
    }
    l = 1;
    r = pos.back().first;
    int cl = 0,cr = n - 1;
    while(l < r)
    {
        int siz = min(pos[cl].first - l + 1,r - pos[cr - 1].first);
        if(pos[cl].second != pos[cr].second) ans += siz;
        l += siz;
        r -= siz;
        if(l > pos[cl].first) cl++;
        if(r <= pos[cr - 1].first) cr--;
    }
    cout<<ans<<"\n";
}