#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,ans=0;
struct strings
{
    int num;
    char val;
};
deque<strings> q;
signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    while(n--)
    {
        strings x;
        cin>>x.num>>x.val;
        q.push_back(x);
    }
    while(!q.empty())
    {
        int flag;
        strings x=q.front();
        q.pop_front();
        if(q.empty())
        {
            break;
        }
        strings y=q.back();
        q.pop_back();
        if(x.val==y.val)
        {
            flag=0;
        }
        else
        {
            flag=1;
        }
        if(x.num>y.num)
        {
            x.num-=y.num;
            q.push_front(x);
            ans+=flag*y.num;
            continue;
        }
        if(x.num<y.num)
        {
            y.num-=x.num;
            q.push_back(y);
            ans+=flag*x.num;
            continue;
        }
        if(x.num==y.num)
        {
            ans+=flag*x.num;
            continue;
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
