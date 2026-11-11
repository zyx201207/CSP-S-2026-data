#include<bits/stdc++.h>
using namespace std;
struct node
{
    int l;
    char c;
};
deque<node> dq;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,x;cin >> n;
    char y;
    long long ans = 0;
    for(int i = 1;i <= n;i++)
    {
        cin >> x;
        cin >> y;
        dq.push_back({x,y});
    }
    int l1,l2;
    char c1,c2;
    while(dq.size() >= 2)
    {
        l1 = dq.front().l;l2 = dq.back().l;
        c1 = dq.front().c;c2 = dq.back().c;
        dq.pop_front();dq.pop_back();
        if(l1 == l2)
            if(c1 != c2)
                ans += l1;
        if(l1 > l2)
        {
            if(c1 != c2)ans += l2;
            dq.push_front({l1-l2,c1});
        }
        if(l1 < l2)
        {
            if(c1 != c2)ans += l1;
            dq.push_back({l2-l1,c2});
        }
    }
    cout << ans;
    return 0;
}
