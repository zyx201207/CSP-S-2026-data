#include<bits/stdc++.h>
using namespace std;
struct node{
    long long a;
    char c;
};
deque<node> q;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        node ac;
        cin>>ac.a>>ac.c;
        q.push_back(ac);
    }
    long long ans=0;
    while(!q.empty())
    {
        node s=q.front();
        node e=q.back();

        q.pop_back();
        if(!q.empty())
            q.pop_front();
        if(s.c==e.c)
        {
            if(s.a>e.a)
            {
                s.a=s.a-e.a;
                q.push_front(s);
            }
            else
            if(s.a<e.a)
            {
                e.a=e.a-s.a;
                q.push_back(e);
            }
        }
        else
        {
            if(s.a>e.a)
            {
                ans+=e.a;
                s.a=s.a-e.a;
                q.push_front(s);
            }
            else
            if(s.a<e.a)
            {
                ans+=s.a;
                e.a=e.a-s.a;
                q.push_back(e);
            }
            else
            {
                ans+=s.a;
            }
        }
    }
    cout<<ans;
    return 0;
}

